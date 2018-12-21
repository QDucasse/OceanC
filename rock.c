#include <stdlib.h>
#include "rock.h"

//Initialize a rock with a given position
rock *initialize_rock(int x, int y){
    rock *my_rock;
    my_rock=malloc(sizeof(rock));
    *(my_rock->pos)=x;
    *((my_rock->pos)+1)=y;
    return my_rock;
}


int main()
{
    rock* blabla = initialize_rock(2,4);
    int blablabla = *(blabla->pos);
    return 0;
}
