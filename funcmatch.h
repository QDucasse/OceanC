#ifndef FUNCMATCH_H
#define FUNCMATCH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ocean.h"
#include "network_tools.h"

/* Treats incoming commands from the clients: visualize, modify_speed, modify_direction, say and stop/quit */
int funcmatch(char* command, int id,ocean *oc);


#endif //FUNCMATCH_H
