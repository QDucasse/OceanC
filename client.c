#include <stdio.h> 
#include <string.h> 
#include <errno.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <netdb.h>
#include <signal.h>

int socket_d;

void error(char *msg) {
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1); 
} //error

int catch_signal(int sig, void (*handler)(int)) {
	struct sigaction action; 
	action.sa_handler = handler; 
	sigemptyset(&action.sa_mask); 
	action.sa_flags = 0;
	return sigaction (sig, &action, NULL); 
} //catch_signal

void handle_shutdown(int sig) {
	//Closes the socket in case of use of Ctrl-C
	if (socket_d) 
		close(socket_d);
	fprintf(stderr, "Socket closed!\n");
	exit(0);
} //handle_shutdown

int open_listener_socket() {
	int listener_d = socket(AF_INET, SOCK_STREAM, 0); 
	if (listener_d == -1)
		error("Cannot open socket");
	return listener_d; //returns a listener socket descriptor
} //open_listener_socket

int open_socket(char *host, char *port) {
	struct addrinfo *res;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints)); 
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if (getaddrinfo(host, port, &hints, &res) == -1)
		error("Cannot resolve the address");
	int d_sock = socket(res->ai_family, res->ai_socktype,res->ai_protocol);
	if (d_sock == -1) 
		error("Can't open socket");
	int c = connect(d_sock, res->ai_addr, res->ai_addrlen); 
	freeaddrinfo(res);
	if (c == -1)
		error("Can't connect to socket"); 
	return d_sock;
} 




