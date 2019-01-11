#ifndef OCEAN_H
#define OCEAN_H

/* <stdlib.h> | <stdio.h> included in boat->wind */
#include "rock.h"
#include "boat.h"
#include "wind.h"
#include <math.h>

typedef struct ocean {
    int X;
    int Y;
    FILE* config;
    int* registery; /*Annuaire qui contient les adresses clients etc.*/
    wind* wind;
} ocean;

/*Initialize an ocean with a given size and wind properties*/
ocean *initialize_ocean(int x, int y, int strength, int direction);

/*Move all boats registered in the ocean*/
void move_one_step(ocean *my_ocean);
/* Extraction of the number of boats
 * Extraction of all the pointers in a list
 * For loop for every boat, in the registration order
    * Estimate
    * For estimate not free
        * Dodge*/

/*Add a boat in the ocean at a given position*/
void add_boat(ocean *my_ocean, boat *my_boat, int x, int y);

/*Add a rock in the ocean at a given position*/
void add_rock(ocean *my_ocean, rock *my_rock, int x, int y);

/*Display the whole map with rocks and boats*/
char *ocean_display(ocean *my_ocean);

/*Estimate a given boat's next position*/
int *estimate(boat *my_boat, wind *wind, ocean *ocean);

#endif /* OCEAN_H */


