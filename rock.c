#include <stdlib.h>
#include "rock.h"

//Initialize a rock with a given position
rock *initialize_rock(int x, int y){
    my_rock=malloc(sizeof(rock));
    *(my_rock->pos)=x;
    *((my_rock->pos)+1)=y;
    return my_rock;
}

//Add a given rock to a given ocean
void add_rock(rock *my_rock, ocean *my_ocean){
    
}

//Delete a given rock from a given ocean
void delete_rock(rock *my_rock, ocean *my_ocean);

int main()
    {

    return 0
    }
