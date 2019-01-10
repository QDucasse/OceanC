#include "ocean.h"

/* argc is the number of arguments
 * argv is an array of pointer on char on each argument
 * ex:
 *  $ program_name input.f32le output.f32le
 *    |            |           |
 *    argv[0]      argv[1]     argv[2]        and argc = 3*/

/*Initialize an ocean with a given size and wind direction+strength*/
ocean *initialize_ocean(int x, int y, int strength, int direction){
	ocean *oc = malloc(sizeof(ocean)); //memory allocation of the ocean structure
	oc->X = x;
	oc->Y = y;
/*	oc->map = fopen();
 *	oc->registery  */
	//oc->wind = initialize_wind(strength,direction);
	return oc;
};

/*Move all boats registered in the ocean*/
void move_one_step(ocean *my_ocean){
   /* Extraction of the number of boats
    * Extraction of all the pointers in a list
    * Loop for every boat, in the registration order
       * Estimate position
       * While (not free) or (i != 4) : (estimate position) if not free
           * Dodge */	
};

/*Add a boat in the ocean at a given position*/
void add_boat(ocean *my_ocean, boat *my_boat, int x, int y){
	//Placer le bateau
	//Ajouter le bateau à l'annuaire
	//Rendre la position du bateau à l'utilisateur
};

/*Add a rock in the ocean at a given position*/
void add_rock(ocean *my_ocean, rock *my_rock, int x, int y){
	//Rendre la position du caillou
};

/*Display the whole map with rocks and boats*/
char *ocean_display(ocean *my_ocean);

/*Make a boat dodge an obstacle*/

int main(){
	return 0;
}

