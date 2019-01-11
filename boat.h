#ifndef BOAT_H
#define BOAT_H
/* <stdlib.h> | <stdio.h> included in wind.h */
#include "wind.h"

typedef struct BOAT{
    int pos[2];
    char nom[10];
    direction d;
    int speed;
} boat;

//Initialize a boat with a given name, position, direction and speed
boat *initialize_boat(char* name, int x, int y, direction dir, int spd);

//Change direction into the one wished
void change_direction(boat *my_boat, direction dir);

//Change direction from the current one
void turn_right(boat *my_boat);

//Change boat speed 
void change_speed(boat *my_boat,int speed); 
//Influe sur la vitesse d'un bateau

#endif /* BOAT_H */
