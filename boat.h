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

///Initialize a boat with a given name, position, direction and speed
boat *initialize_boat(char* name, int x, int y, direction dir, int spd);

//Estimate a given boat's next position, taking the wind into consideration
int *estimate(boat *my_boat, wind *wind);

//Change direction into the one wished
void change_direction(boat *my_boat, direction dir);

//Change direction from the current one
void turn_left(boat *my_boat);

//Change boat speed 
void change_speed(boat *my_boat,int speed); 
//Influe sur la vitesse d'un bateau

//Displays the boat's direction
void affdir(boat *my_boat);

//Update the boat's speed
void Up_speed(boat *my_boat, wind *wind);

#endif /* BOAT_H */
