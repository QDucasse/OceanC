#include "boat.h"


// Initialize a boat with a given name, position, direction and speed
boat *initialize_boat(char* name, int x, int y, direction dir, int spd){
    boat *my_boat;
    my_boat=malloc(sizeof(boat));
    *(my_boat->nom)=*name;
    *(my_boat->pos)=x;
    *((my_boat->pos)+1)=y;
    my_boat->d=dir;
    my_boat->speed=spd;
    return my_boat;
}

// Turn the boat in the direction wished
void change_direction(boat *my_boat, direction dir)
{
    my_boat->d=dir;
}

// Turn the boat in the left direction
void turn_right(boat *my_boat)
{
    my_boat->d=my_boat->d+1;
}


//Change boat speed with saturation outside [0,20]
void change_speed(boat *my_boat,int speed)
{
    if (speed<0)
    {
        my_boat->speed=0;
    }
    else if (speed>20)
    {
        my_boat->speed=20;
    }
    else
    {
        my_boat->speed=speed;
    }
}


/*Main et Tests*/
int main()
{
    //Test Initialisation
    direction dbIni=N;
    boat* bIni = initialize_boat("jean",2,4,dbIni,1);
    int testIni1 = (*(bIni->nom) == 'j');
	int testIni2 = ((*(bIni->pos)) == 2);
    int testIni3 = (*((bIni->pos)+1) == 4);
    int testIni4 = ((bIni->d) == dbIni);
    int testIni5 = ((bIni->speed) == 1);
	int resIni = testIni1 && testIni2 && testIni3 && testIni4 && testIni5;
    printf("Initialization test: %d\n",resIni);
    
    //Test changing parameters
    turn_right(bIni);
    int testChg1 = ((bIni->d) == E);
	printf("Turn right test: %d\n",testChg1);
    
    change_direction(bIni, W);
    int testChg2 = ((bIni->d) == W);
	printf("Change direction test: %d\n",testChg2);
    
    change_speed(bIni,2);
    int testChg3 = ((bIni->speed) == 2);
	printf("Change speed test: %d\n",testChg3);

    change_speed(bIni,48);
    int testChg4 = ((bIni->speed) == 20);
	printf("Change speed test2: %d\n",testChg4);
    
    return 0;
}
