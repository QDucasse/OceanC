#ifndef NETWORK_TOOLS_H
#define NETWORK_TOOLS_H

/* <stdlib.h> | <stdio.h> included in funcmatch->ocean->boat->wind */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>

/* Error and signal handling */
void error(char *msg);
int catch_signal(int sig, void (*handler)(int));

/* Server-Client basics, often built-in functions with error handling added to it */
void bind_to_port(int socket, int port);
int open_socket();
void listen_socket(int listener_d,int queue);
int accept_connection(int listener_d,struct sockaddr_storage client_addr,unsigned int address_size);

/* Server-Client communication */
int read_in(int socket, char *buf, int len);
int say(int socket, char *s);

#endif //NETWORK_TOOLS_H

