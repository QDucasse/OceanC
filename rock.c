#include "rock.h"

/* Initializes a rock with a given position */
rock *initialize_rock(int x, int y){
    rock *my_rock;
    my_rock=malloc(sizeof(rock));
    *(my_rock->pos)=x;
    *((my_rock->pos)+1)=y;
    return my_rock;
}

#ifdef LOCAL_ROCK //This variable definition allows us to keep a single main in the server/client while keeping tests here in case of its definition
int main()
{
	//Test Initialisation
	rock *rIni = initialize_rock(5,6);
	int testIni1 = ((*(rIni->pos)) == 5);
	int testIni2 = ((*(rIni->pos)+1) == 6);
	int resIni = testIni1 && testIni2;
	printf("Initialization test: %d\n",resIni);
    return 0;
}
#endif