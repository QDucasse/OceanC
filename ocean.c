#include "ocean.h"

registery *initialize_registery(nb_boats){
	registery *reg = malloc(sizeof(registery));
	reg->nb_boats = nb_boats;
	reg->names = malloc(20*sizeof(char)*nb_boats);
	reg->speeds = malloc(sizeof(int)*nb_boats); 
	reg->directions = malloc(sizeof(direction)*nb_boats);
	reg->coordX = malloc(sizeof(int)*nb_boats);
	reg->coordY = malloc(sizeof(int)*nb_boats); 
	reg->socket_desc = malloc(sizeof(int)*nb_boats); 
	return reg;
}

/*Initialize an ocean with wind direction+strength*/
ocean *initialize_ocean(int strength, int direction){
	ocean *oc = malloc(sizeof(ocean)); //memory allocation of the ocean structure
    
    //Ocean dimensions initialization
    FILE* conf = fopen("config.txt","ab+");
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
    oc->reg = initialize_registery(8);

    //Wind initialization
	oc->wind = initialize_wind(strength,direction);
	
    //Boat list initialization
    oc->boat_list = malloc(8*sizeof(boat));
	return oc;
};

/*Move all boats registered in the ocean*/
void move_one_step(ocean *oc){
	int i;
	for (i=0;i<8;i++){
		boat *current_boat = &(oc->boat_list[i]);
		for (i=0;i<4;i++){
			//int new_pos = *estimate(current_boat,oc->wind,oc);
			//Vérification si la nouvelle position entre en collision avec un autre bateau ou un rocher
			///Si oui re-estimate
			////Si re-estimate 4 fois, ne pas bouger
			///Sinon changer la position	
		}
	}
};

/*Add a boat in the ocean at a given position*/
void add_boat(ocean *my_ocean, boat *my_boat, char* name, int x, int y, int socket_d) //Cette fonction est commentée car elle bloque la compilation
{ /*	
    direction D = E;
    *(&(my_ocean->boats)+my_ocean->nb_boats) = initialize_boat(name, x, y, D, 2);
    *(*(my_ocean->reg) + my_ocean->nb_boats) = *name;
    *(*(&(my_ocean->reg)+1) + 8) = 2;
    *(*(&(my_ocean->reg)+2) + 8) = D;
    *(*(&(my_ocean->reg)+3) + 8) = socket_d;
    *(*(&(my_ocean->reg)+4) + 8) = x;
    *(*(&(my_ocean->reg)+5) + 8) = y;  */
};

/*Display the whole map with rocks and boats*/
void ocean_display(ocean *my_ocean)		//Cette fonction est commentée car elle bloque la compilation
{ /*				
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
            // Rocher 
            for (k=0;k<u-2;k++)
            {
                if (i==*(RocksX+k) && j==*(RocksY+k))
                {
                    printf("[R]");
                    Found = 1;
                }
            }
            
            // Bateau 
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
            
            // Mer 
            if (Found==0)
            {
                printf("~~~");
            }
        }
    printf("\n");
    } */
};

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
