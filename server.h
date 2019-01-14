#ifndef SERVER_H
#define SERVER_H

#include "network_tools.h"
#include "funcmatch.h"

/* Function executed in a thread allowing the user to change the wind strength or direction */
void *thread_modif_wind();
	
/* Function executed in a thread in case of a client connecting */
void *connection_handler(void *socket_desc);

/* Function executed in a thread moving all boats every second */
void *thread_boat_movement();
	
/* Gives a default behavior to the server in case of Ctrl-C */
void handle_shutdown_server(int sig);

#endif //SERVER_H

