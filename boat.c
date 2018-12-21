#include <stdlib.h>
#include <stdio.h>
#include "boat.h"
#include "wind.h"

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

// Turn the boat in the direction wished
void change_direction(boat *my_boat, direction dir)
{
    my_boat->d=dir;
}

// Turn the boat in the left direction
void turn(boat *my_boat)
{
    my_boat->d=my_boat->d+1;
}

// Displays the boat's direction
void affdir(boat *my_boat)
{
    switch(my_boat->d)
    {
        case NORTH: printf("North\n"); break;
        case EAST: printf("East\n"); break;
        case SOUTH: printf("South\n"); break;
        case WEST: printf("West\n");
    }
}

//Change boat speed with saturation outside [0,20]
void change_speed(boat *my_boat,int speed)
{
    if (speed<0):
    {
        my_boat->speed=0;
    }
    else if (speed>20):
    {
        my_boat->speed=20;
    }
    else
    {
        my_boat->speed=speed;
    }
}

//Estimate a given boat next position
int *estimate(boat *my_boat, wind *wind)
{
    int* pos_estimated[2];
    
}


int main()
{
    direction go=NORTH;
    boat* blabla = initialize_boat("jean",2,4,go,1);
    affdir(blabla);
    
    turn(blabla);
    affdir(blabla);
    
    change_direction(blabla, go+3);
    affdir(blabla);

    change_speed(blabla,2);
    printf("%d\n",blabla->speed);

    change_speed(blabla,48);
    printf("%d\n",blabla->speed);
    return 0;
}
