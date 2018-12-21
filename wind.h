#ifndef WIND_H
#define WIND_H

typedef enum {
    NORTH,EAST,SOUTH,WEST
}direction;

typedef struct {
    int strength;
    enum direction d;
} wind;

//Here we declare the prototype of our functions

/*Initialize a wind with a given strength and direction*/
wind *initialize_wind(int strength, direction d);

/*Change wind parameters: strength and/or direction*/
void change_param_wind(wind *my_wind,int strength, direction d); 

#endif //WIND_H

