#ifndef BOAT_H
#define BOAT_H

#include "wind.h"

typedef struct BOAT{
    int pos[2];
    char nom[10];
    direction d;
    int speed;
} boat;

/* Initializes a boat with a given name, position, direction and speed */
boat *initialize_boat(char* name, int x, int y, direction dir, int spd);

/* Changes the direction of a boat */
void change_direction(boat *my_boat, direction dir);

/* Turns the boat clockwise */
void turn_right(boat *my_boat);

/* Changes the speed of the boat */
void change_speed(boat *my_boat,int speed); 

#endif /* BOAT_H */
