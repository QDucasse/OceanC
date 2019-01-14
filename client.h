#ifndef CLIENT_H
#define CLIENT_H

#include "network_tools.h"
#include "ocean.h"

/* Gives the client a default behavior in case of Ctrl-C */
void handle_shutdown_client(int sig);

#endif //CLIENT_H