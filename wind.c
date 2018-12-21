#include <stdlib.h>
#include <stdio.h>
#include "wind.h"


/*Initialize a wind with a given position*/
wind *initialize_wind(int strength, direction d){
	*wind w = malloc(sizeof(wind)); //memory allocation of the wind structure
	w->strength = strength;
	w->direction = d;
	return w;
};

/*Change wind parameters: strength and/or direction*/
void change_param_wind(wind *my_wind,int strength, direction d){
	my_wind->strength = strength;
	my_wind->direction = d;
}; 





