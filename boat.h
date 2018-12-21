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

//Initialize a boat with a given position
boat *initialize_boat(int x, int y, char *nom, direction d, int speed);
//malloc() done here

//Estimate a given boat next position
int *estimate(boat *my_boat, wind *wind);
//Calcule la future position du bateau

//Dodge an obstacle
int *dodge(boat *my_boat); 
//Résulte en un changement de cap

//Add a given boat to a given ocean
void add_boat(boat *my_boat, ocean *my_ocean);

//Change boat speed 
void change_speed(boat *my_boat,int speed); 
//Influe sur la vitesse d'un bateau

//Change boat direction 
void change_direction(boat *my_boat, direction d); 
//Influe sur la vitesse d'un bateau

//Delete a given boat from a given ocean
void delete_boat(rock *my_boat, ocean *my_ocean);






