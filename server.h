#ifndef SERVER_H
#define SERVER_H

#include "network_tools.h"

void handle_shutdown(int sig);

int accept_connection(int listener_d,struct sockaddr_storage client_addr,unsigned int address_size);

int read_in(int socket, char *buf, int len);

int say(int socket, char *s);

#endif //SERVER_H

