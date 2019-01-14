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
	//Runs the code handle_shutdown_client if Ctrl-C is used
	if (catch_signal(SIGINT, handle_shutdown_client) == -1) 
		error("Cannot set the interrupt handler");
	
	//Argument storage
	struct hostent *host=gethostbyname(argv[1]);
	int port=atoi(argv[2]);
	char *name = argv[3];
	int speed = atoi(argv[4]);
	direction d = strtodir(*argv[5]);
	
	//Open 
	socket_d = open_socket(); 
	
	puts("Connection...");
	char buf_cli[255];
	printf("%d\n",port);
	printf("%s\n",name);
	printf("%d\n",speed);
	connect_client(socket_d, host, port);
	
} //main()




