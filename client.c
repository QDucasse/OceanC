#include <stdio.h> 
#include <string.h> 
#include <errno.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <netdb.h>
#include <signal.h>

int listener_d;

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
	if (listener_d) 
		close(listener_d);
	fprintf(stderr, "Socket closed!\n");
	exit(0);
} //handle_shutdown
