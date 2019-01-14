#include "server.h"
 
int listener_d;
int connect_d;
ocean *oc;

void handle_shutdown_server(int sig) {
	//Closes the socket in case of use of Ctrl-C
	if (listener_d) 
		close(listener_d);
	fprintf(stderr, "Socket closed!\n");
	exit(0);
} //handle_shutdown_server

void *thread_modif_wind(){
	char command[50];
	while(1){
		scanf("%s",command);
		if(strncasecmp("w_speed",command,7)==0){
			change_str_wind(oc->wind,command[8]);
		}
		if(strncasecmp("w_direction",command,11)==0){
			change_dir_wind(oc->wind, strtodir(command[12]));
		}
	}
}


void *thread_boat_movement(){
	while(1){
		int i;
		move_one_step(oc);
		sleep(1);
	}
}

void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int connect_d = *(int*)socket_desc;
	char buf_cli[500];
	
    //Send manual
	if(say(connect_d,"\nWelcome in OceanC, a C-based ocean simulator\nThe options you can use are the following:\n\n1- Modify the variables of your boat (speed, direction) ------ Use one of the following\n\t------------------------------------------------------ 'modif_speed newSpeed'\n\t------------------------------------------------------ 'modif_dir newDirection'\n2- Display a message to other boats -------------------------- 'say yourMessage'\n3- Visualize the current ocean ------------------------------- 'visualize'\n\n") != -1)	
	{
		//First read_in then looping while the client enters "quit" or "stop"
		read_in(connect_d,buf_cli,sizeof(buf_cli));
		while(funcmatch(buf_cli,2,oc)){ //2 is an example here
			read_in(connect_d,buf_cli,sizeof(buf_cli));
		}
        //Handle the command the client will send back
	}
    //Free the socket pointer
    return 0;
}

int main(int argc, char *argv[]) {
	//Runs the code handle_shutdown_server if Ctrl-C is used
	if (catch_signal(SIGINT, handle_shutdown_server) == -1) 
		error("Cannot set the interrupt handler");
	
	//Initializing the ocean
	//ocean *oc = initialize_ocean(10,10,3,1);
	if (argc != 2)
		error("Wrong number of arguments");
	//Port we will be using
	int port = atoi(argv[1]);
	
	//Open 
	listener_d = open_socket(); 
	puts("Socket opened!");
	
	//Bind
	bind_to_port(listener_d, port); 
	puts("Socket bounded!");
	
	//Listen
	listen_socket(listener_d,8);
	puts("Waiting for incoming connections...");
	/*Variable definition: 
	  client_addr ---- client address
	  address_size --- size of the address
	  buf ------------ buffer where the server will read messages from the clients */
	struct sockaddr_storage client_addr;
	unsigned int address_size = sizeof(client_addr);
	char buf_serv[255];
	int id = 0;
	
	pthread_t thread_wind;
	pthread_t thread_movement;

	if(pthread_create(&thread_wind, NULL, thread_modif_wind, NULL)==-1)
		error("Cannot join thread_wind");
	
	direction dir = N;
	oc = initialize_ocean(2,dir);
	//Now we should loop the wait and create a new process for every incoming client
	while((connect_d = accept(listener_d, (struct sockaddr *)&client_addr,&address_size))!=-1){
			printf("A client connection has been accepted with the id: %d\n",id);
			id ++;
	        pthread_t connection_thread;

	        // Copy the value of the accepted socket, in order it to pass to the thread
	        int *new_sock = malloc(4);
			*new_sock = connect_d; 

	        // Create new thread  
	        if(pthread_create(&connection_thread, NULL, connection_handler, (void*) new_sock) < 0)
	            error("Could not create thread for the connection handler");
			puts("Handler assigned");
			
	        //Now join the thread , so that we dont terminate before the thread
	        pthread_join(connection_thread, NULL);   
	}
} //main()

//Mutex sur la carte?? annuaire??



