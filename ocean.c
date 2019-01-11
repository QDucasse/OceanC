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
    oc->registery = &reg;
    
    //initialisation du vent 
	oc->wind = initialize_wind(strength,direction);
    
    //initialisation du fichier config
    oc->config = fopen("Config.txt","ab+");
    if (&oc->config==NULL)
    {
        printf("Error!");
        exit(1);
    }
    fwrite("\n",sizeof(int),1,oc->config);
    fwrite(&oc->Y,sizeof(int),1,oc->config);
    fwrite("\n",sizeof(int),1,oc->config);
    fwrite("[1,2]\n[5,5]\n[4,1]\n",sizeof(int),1,oc->config);
    
    fclose(oc->config);
    
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
/*
char *ocean_display(ocean *my_ocean)
{

};
*/

/*Make a boat dodge an obstacle*/

/*Estimate a given boat's next position*/
int *estimate(boat *my_boat, wind *wind, ocean *ocean)
{
    int *pos_estimated=malloc(2*sizeof(int));
    *pos_estimated=*my_boat->pos;
    *(pos_estimated+1)=*(my_boat->pos)+1;
    
    //Boat speed part
    switch(my_boat->d)
    {
        case N:
            *(pos_estimated+1)=(*((my_boat->pos)+1+(int)floor(my_boat->speed)))%ocean->Y;
            break;
        case E:
            *pos_estimated=(*(my_boat->pos+(int)floor(my_boat->speed)))%ocean->X;
            break;
        case S:
            *(pos_estimated+1)=(*((my_boat->pos)+1-(int)floor(my_boat->speed)))%ocean->Y+ocean->Y;
            break;
        case W: 
            *pos_estimated=(*(my_boat->pos-(int)floor(my_boat->speed)))%ocean->X+ocean->X;
    }
    
    //Wind influence part
    switch(wind->dir)
    {
        case N:
            *(pos_estimated+1)=(*((my_boat->pos)+1)+wind->strength)%ocean->Y;
            break;
        case E:
            *pos_estimated=(*(my_boat->pos)+wind->strength)%ocean->X;
            break;
        case S: 
            *(pos_estimated+1)=(*((my_boat->pos)+1)-wind->strength)%ocean->Y+ocean->Y;
            break;
        case W:
            *pos_estimated=(*(my_boat->pos)-wind->strength)%ocean->X+ocean->X;
    }
    return pos_estimated;
};


#ifdef LOCAL_OCEAN
int main()
{
    //Test Initialisation
    direction dIni = N;
    ocean* oIni = initialize_ocean(20,18,2,dIni);
    int testIni1 = ((oIni->X) == 20);
	int testIni2 = ((oIni->Y) == 18);
    int testIni3 = ((oIni->wind->strength) == 2);
    int testIni4 = ((oIni->wind->dir) == dIni);
	int resIni = testIni1 && testIni2 && testIni3 && testIni4;
    printf("Initialization test: %d\n",resIni);
    
    
	return 0;
}
#endif
