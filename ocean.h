#ifndef OCEAN_H
#define OCEAN_H

typedef struct {
    int X;
    int Y;
    FILE map; 
    FILE directory; /*Annuaire qui contient les adresses clients etc.*/
    wind *wind;
} ocean;

/*Initialize an ocean with a given size*/
ocean *initialize_ocean(int x, int y);

/*Move all boats registered in the ocean*/
void move_one_step(ocean *my_ocean);
/* Extraction of the number of boats
 * Extraction of all the pointers in a list
 * For loop for every boat, in the registration order
    * Estimate
    * For estimate not free
        * Dodge*/

/*Add a boat in the ocean at a given position*/
void add_boat(ocean *my_ocean, boat *my_boat);

/*Add a rock in the ocean at a given position*/
void add_boat(ocean *my_ocean, boat *my_boat);

/*Display the whole map with rocks and boats*/
char *ocean_display(ocean *my_ocean);

#endif //OCEAN_H


