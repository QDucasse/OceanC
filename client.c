#include "client.h"

int socket_d;

void handle_shutdown_client(int sig) {
	//Closes the socket in case of use of Ctrl-C
	if (socket_d) 
		close(socket_d);
	fprintf(stderr, "Client socket closed!\n");
	exit(0);
} //handle_shutdown

int main(int argc, char *argv[]) {
	//Runs the code handle_shutdown if Ctrl-C is used
	if (catch_signal(SIGINT, handle_shutdown_client) == -1) 
		error("Cannot set the interrupt handler");
	
	//Port we will be using
	int port = 6543;
	
	//Open 
	socket_d = open_socket(); 
	
	puts("Connection...");
	char buf_cli[255];

	/*
		
		if(!fork()) {
			//We are in the child process here
			//Le serveur doit prendre en charge le bateau qui arrive
					//Ajouter à l'annuaire
					//Ajouter à la carte
			close(listener_d); //The child will only need the connect_d socket generated by accept()
			if(say(connect_d,"\nWelcome in OceanC, a C-based ocean simulator\nThe options you can use are the following:\n\n1- Modify the variables of your boat (speed, direction) ------ Use one of the following\n\t------------------------------------------------------ 'modif_speed newSpeed'\n\t------------------------------------------------------ 'modif_dir newDirection'\n2- Display a message to other boats -------------------------- 'say yourMessage'\n3- Visualize the current ocean ------------------------------- 'visualize'\n\n") != -1)	
			   {
				
			   }
			}	//if(say(...
			close(connect_d);
			exit(0);
		} */
} //main()




