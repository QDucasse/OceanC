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
    
    //initialisation des dimensions de l'océan
    FILE* conf = fopen("Config.txt","ab+");
    if (conf == NULL)
    {
        fprintf(stderr,"Could not open file");
    }
    char line[10];
    int u = 0;
    while (fgets(line,sizeof(line),conf)!=NULL)
    {
        switch(u)
        {
            case 0: oc->X=atoi(line); break;
            case 1: oc->Y=atoi(line); break;
        }
        u++;
    }
    fclose(conf);
    
    //initialisation du registre
    int *reg = malloc(6*sizeof(int)); //6 colonnes du registre
    int *noms = malloc(20*sizeof(char)*8); //colonne noms
    int *vitesses = malloc(sizeof(int)*8); //colonne vitesses
    int *directions = malloc(sizeof(direction)*8); //colonne directions
    int *ports = malloc(sizeof(int)*8); //colonne ports
    int *coordsX = malloc(sizeof(int)*8); //colonne coordonnées x
    int *coordsY = malloc(sizeof(int)*8); //colonne coordonnées y
    *reg = &noms;
    *(reg+1) = &vitesses;
    *(reg+2) = &directions;
    *(reg+3) = &ports;
    *(reg+4) = &coordsX;
    *(reg+5) = &coordsY;
    *(oc->registery) = &reg;
    int i;
    for (i=0;i<8;i++)
    {
        *(*(&(oc->registery)+4)+i)=oc->X+1;
        *(*(&(oc->registery)+5)+i)=oc->Y+1;
    }
    
    //initialisation du vent 
	oc->wind = initialize_wind(strength,direction);
    
    //initialisation de la liste des pointeurs bateau
    oc->boats = malloc(8*sizeof(boat));
    oc->nb_boats = 0;
    
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
void add_boat(ocean *my_ocean, boat *my_boat, char* name, int x, int y, int port)
{
    direction D = E;
    *(&(my_ocean->boats)+my_ocean->nb_boats) = initialize_boat(name, x, y, D, 2);
    *(*(my_ocean->registery) + my_ocean->nb_boats) = *name;
    *(*(&(my_ocean->registery)+1) + my_ocean->nb_boats) = 2;
    *(*(&(my_ocean->registery)+2) + my_ocean->nb_boats) = D;
    *(*(&(my_ocean->registery)+3) + my_ocean->nb_boats) = port;
    *(*(&(my_ocean->registery)+4) + my_ocean->nb_boats) = x;
    *(*(&(my_ocean->registery)+5) + my_ocean->nb_boats) = y;
};

/*Add a rock in the ocean at a given position*/
void add_rock(ocean *my_ocean, rock *my_rock, int x, int y){
	//Rendre la position du caillou
};

/*Display the whole map with rocks and boats*/

void ocean_display(ocean *my_ocean)
{
    // Récupération des coordonnées des rochers dans Config.txt
    FILE* conf = fopen("Config.txt","ab+");
    if (conf == NULL)
    {
        fprintf(stderr,"Could not open file");
    }
    char line[10];
    int u = 0;
    int* RocksX = malloc(sizeof(int)*20);
    int* RocksY = malloc(sizeof(int)*20);
    while (fgets(line,sizeof(line),conf)!=NULL)
    {
        switch(u)
        {
            case 0: break;
            case 1: break;
            default: sscanf(line,"%d %d",RocksX+u-2,RocksY+u-2);
        }
        u++;
    }
    
    fclose(conf);
    
    // Ecriture de la carte
    int i, j, k;
    for (i=0;i<my_ocean->X;i++)
    {
        for (j=0;j<my_ocean->Y;j++)
        {
            int Found = 0;
            /* Rocher */
            for (k=0;k<u-2;k++)
            {
                if (i==*(RocksX+k) && j==*(RocksY+k))
                {
                    printf("[R]");
                    Found = 1;
                }
            }
            
            /* Bateau */
            if (Found==0)
            {
                for (k=0;k<8;k++)
                {
                    if (i==*(*(&(my_ocean->registery)+4)+k) && j==*(*(&(my_ocean->registery)+5)+k))
                    {
                        printf("<i>");
                        Found = 1;
                    }
                }
            }
            
            /* Mer */
            if (Found==0)
            {
                printf("~~~");
            }
        }
    printf("\n");
    }
};


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
    
    //Test d'affichage de la carte
    ocean_display(oIni);
    
	return 0;
}
#endif
