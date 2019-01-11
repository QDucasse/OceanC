#include "network_tools.h"

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

int open_socket() {
	int socket_d = socket(AF_INET, SOCK_STREAM, 0); 
	if (socket_d == -1)
		error("Cannot open socket");
	return socket_d; //returns a socket descriptor
} //open_socket

void bind_to_port(int socket, int port) {
	struct sockaddr_in name; //Contexte d'adressage
	name.sin_family = AF_INET;
	name.sin_port = (in_port_t)htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;
	if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
		error("Cannot set the reuse option on the socket"); 
	//The reuse option allows us to reboot the server immediately if shut down
	//The lack of it would make us wait for 30 seconds for the port to be cleaned and made free
	int c = bind (socket, (struct sockaddr *) &name, sizeof(name));
	if (c == -1)
		error("Cannot bind to socket"); 
} //bind_to_port

void listen_socket(int listener_d,int queue){
	if(listen(listener_d,queue)==-1)
		error("Cannot listen");
} //listen_socket

int accept_connection(int listener_d,struct sockaddr_storage client_addr,unsigned int address_size){
	int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
		//Wait until a client contacts the server
		//Create a secondary socket descriptor to hold the conversation with the client
	if (connect_d == -1)
		error("Cannot open secondary socket");
	return connect_d;
} //accept_connection

int read_in(int socket, char *buf, int len) {
	char *s = buf;
	int slen = len;
	int c = recv(socket, s, slen, 0); 
	while ((c > 0) && (s[c-1] != '\n')) {
		s += c; slen -= c;
		c = recv(socket, s, slen, 0);
	}
	if (c < 0) 
		return c;
	else if (c == 0) 
		buf[0] = '\0';
	else 
		s[c-1]='\0';
	return len - slen; 
} //read_in

int say(int socket, char *s) { 
	//Send a string to a client
	int result = send(socket, s, strlen(s), 0); 
	if (result == -1)
		fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno)); 
	return result;
} //say

#ifdef LOCAL_NTOOLS
/*Main et Tests*/
int main(){
	return 0;
}
#endif



