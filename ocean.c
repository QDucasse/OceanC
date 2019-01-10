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
    //initialisation du registre
    int *reg = malloc(4*sizeof(int)); //4 colonnes du registre
    int *noms = malloc(20*sizeof(char)*8); //colonne noms
    int *vitesses = malloc(sizeof(int)*8); //colonne vitesses
    int *directions = malloc(sizeof(direction)*8); //colonne directions
    int *ports = malloc(sizeof(int)*8); //colonne ports
    *reg = &noms;
    *(reg+1) = &vitesses;
    *(reg+2) = &directions;
    *(reg+3) = &ports;
    
	oc->wind = initialize_wind(strength,direction);
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
char *ocean_display(ocean *my_ocean)
{
    
}

/*Make a boat dodge an obstacle*/

/*Estimate a given boat's next position*/
int *estimate(boat *my_boat, wind *wind, ocean *ocean)
{
    int *pos_estimated[2]=malloc(2*sizeof(int));
    *pos_estimated=my_boat->pos;
    *(pos_estimated+1)=(my_boat->pos)+1;
    
    //Boat speed part
    switch(my_boat->d)
    {
        case NORTH:
            *(pos_estimated+1)=(*((my_boat->pos)+1+(int)floor(my_boat->speed)))%ocean->Y;
            break;
        case EAST:
            *pos_estimated=(*(my_boat->pos+(int)floor(my_boat->speed)))%ocean->X;
            break;
        case SOUTH:
            *(pos_estimated+1)=(*((my_boat->pos)+1-(int)floor(my_boat->speed)))%ocean->Y+ocean->Y;
            break;
        case WEST: 
            *pos_estimated=(*(my_boat->pos-(int)floor(my_boat->speed)))%ocean->X+ocean->X;
    }
    
    //Wind influence part
    switch(wind->dir)
    {
        case NORTH:
            *(pos_estimated+1)=(*((my_boat->pos)+1)+wind->strength)%ocean->Y;
            break;
        case EAST:
            *pos_estimated=(*(my_boat->pos)+wind->strength)%ocean->X;
            break;
        case SOUTH: 
            *(pos_estimated+1)=(*((my_boat->pos)+1)-wind->strength)%ocean->Y+ocean->Y;
            break;
        case WEST:
            *pos_estimated=(*(my_boat->pos)-wind->strength)%ocean->X+ocean->X;
    }
    return pos_estimated;
}

int main()
{
    ocean Ocean = Initialize_ocean(20,20,
    
    
    
	return 0;
}

