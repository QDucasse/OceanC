#include <stdlib.h>
#include <stdio.h>
#include "boat.h"

// Initialize a boat with a given name, position, direction and speed
boat *initialize_boat(char* name, int x, int y, direction dir, int spd){
    boat *my_boat;
    my_boat=malloc(sizeof(boat));
    *(my_boat->nom)=*name;
    *(my_boat->pos)=x;
    *((my_boat->pos)+1)=y;
    my_boat->d=dir;
    my_boat->speed=spd;
    return my_boat;
}

// Turn the boat in the left direction
void change_direction(boat *my_boat, direction dir)
{
    my_boat->d=my_boat->d+1;
}

// Turn the boat in the direction wished
void turn(boat *my_boat, direction dir)
{
    my_boat->d=dir;
}

// Displays the boat's direction
void affdir(boat *my_boat)
{
    switch(my_boat->d)
    {
        case NORTH: printf("North");
        case EAST: printf("East");
        case SOUTH: printf("South");
        case WEST: printf("West");
    }
}

int main()
{
    direction go=NORTH;
    boat* blabla = initialize_boat("jean",2,4,go,1);
    affdir(blabla);

    turn(blabla, go+1);
    affdir(blabla);
    
    return 0;
}
