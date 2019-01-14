#ifndef OCEAN_H
#define OCEAN_H
#include <math.h>
#include <pthread.h>
/* <stdlib.h> | <stdio.h> included in boat->wind */
#include "rock.h"
#include "boat.h"
#include "wind.h"

typedef struct registery {
	int nb_boats;
    char *names;
    char *speeds;
	direction *directions;
	int *coordX;
	int *coordY;
	int *socket_desc;
} registery;

typedef struct ocean {
    int X;
    int Y;
    FILE* config;
    registery *reg;
    wind* wind;
	boat *boat_list;
} ocean;

/*Initialize a registery*/
registery *initialize_registery(int nb_boats);

/*Initialize an ocean with wind properties*/
ocean *initialize_ocean(int strength, int direction);

/*Move all boats registered in the ocean*/
void move_one_step(ocean *my_ocean);

/*Add a boat in the ocean at a given position*/
void add_boat(ocean *my_ocean, boat *my_boat, char* name, int x, int y, int socket_d);

/*Display the whole map with rocks and boats*/
void ocean_display(ocean *my_ocean);

/*Estimate a given boat's next position*/
int *estimate(boat *my_boat, wind *wind, ocean *ocean);

#endif /* OCEAN_H */


