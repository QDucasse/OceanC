#include <stdlib.h>
#ifndef BOAT_H
#define BOAT_H

typedef enum {
    NORTH,EAST,SOUTH,WEST
}direction;

typedef struct BOAT{
    int pos[2];
    char nom[10];
    direction d; 
    int speed;
} boat;

///Initialize a boat with a given name, position, direction and speed
boat *initialize_boat(char* name, int x, int y, direction dir, int spd);

/*
//Estimate a given boat next position
int *estimate(boat *my_boat, wind *wind);
//Calcule la future position du bateau
*/

//Change direction into the one wished
void change_direction(boat *my_boat, direction dir);
//Résulte en un changement de cap

//Change direction from the current one
void turn_left(boat *my_boat);
//Résulte en un changement de cap

//Change boat speed 
void change_speed(boat *my_boat,int speed); 
//Influe sur la vitesse d'un bateau

//Displays the boat's direction
void affdir(boat *my_boat);

#endif
