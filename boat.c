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
    if (speed<0)
    {
        my_boat->speed=0;
    }
    else if (speed>20)
    {
        my_boat->speed=20;
    }
    else
    {
        my_boat->speed=speed;
    }
}

//Estimate a given boat next position
int *estimate(boat *my_boat, wind *wind, int xOcean, int yOcean)
{
    int* pos_estimated[2];
    *pos_estimated=*(my_boat->pos);
    *(pos_estimated+1)=*((my_boat->pos)+1);
    
    //Boat speed part
    switch(my_boat->d)
    {
        case NORTH:
            *(pos_estimated+1)=(*((my_boat->pos)+1)+floor(my_boat->speed))%yOcean;
            break;
        case EAST:
            *pos_estimated=(*(my_boat->pos)+floor(my_boat->speed))%xOcean;
            break;
        case SOUTH: 
            *(pos_estimated+1)=(*((my_boat->pos)+1)-floor(my_boat->speed))%yOcean+yOcean;
            break;
        case WEST: 
            *pos_estimated=(*(my_boat->pos)-floor(my_boat->speed))%xOcean+xOcean;
    }
    
    //Wind influence part
    switch(wind->dir)
    {
        case NORTH:
            *(pos_estimated+1)=(*((my_boat->pos)+1)+*(wind->strength))%yOcean;
            break;
        case EAST:
            *pos_estimated=(*(my_boat->pos)+*(wind->strength))%xOcean;
            break;
        case SOUTH: 
            *(pos_estimated+1)=(*((my_boat->pos)+1)-*(wind->strength))%yOcean+yOcean;
            break;
        case WEST:
            *pos_estimated=(*(my_boat->pos)-*(wind->strength))%xOcean+xOcean;
    }
    return pos_estimated;
}



int main()
{
    direction go=NORTH;
    direction goWind=EAST;
    boat* bato = initialize_boat("jean",2,4,go,1);
    wind* ww = initialize_boat(2,goWind);
    affdir(bato);
    
    turn(bato);
    affdir(bato);
    
    change_direction(bato, go+3);
    affdir(bato);

    change_speed(bato,2);
    printf("%d\n",bato->speed);

    change_speed(bato,48);
    printf("%d\n",bato->speed);

    printf("x actuel: %d\n",*(bato->pos));
    printf("y actuel: %d\n",*((bato->pos)+1));
    printf("x estimé: %d\n",*estimate(bato, ww, 20, 20));
    printf("y estimé: %d\n",*(estimate(bato, ww, 20, 20)+1));
    
    return 0;
}
