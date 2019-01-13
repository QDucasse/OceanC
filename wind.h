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

/*Initialize a wind with a given strength and direction*/
wind *initialize_wind(int strength, direction d);

/*Change wind parameters: strength and/or direction*/
void change_str_wind(wind *my_wind,int strength); 
void change_dir_wind(wind *my_wind, direction d); 

/* String/Direction conversion */
char dirtostr(direction dir);
direction strtodir(char strdir);
	
#endif //WIND_H

