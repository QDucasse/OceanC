#ifndef WIND_H
#define WIND_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    N,E,S,W
}direction;

typedef struct {
    int strength;
    direction dir;
} wind;

//Here we declare the prototype of our functions

/*Initialize a wind with a given strength and direction*/
wind *initialize_wind(int strength, direction d);

/*Change wind parameters: strength and/or direction*/
void change_param_wind(wind *my_wind,int strength, direction d); 

#endif //WIND_H

