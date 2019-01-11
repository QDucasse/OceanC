#include "wind.h"

/*Initialize a wind with a given position*/
wind *initialize_wind(int strength, direction d){
	wind *w = malloc(sizeof(wind)); //memory allocation of the wind structure
	w->strength = strength;
	w->dir = d;
	return w;
};

/*Change wind parameters: strength and/or direction*/
void change_str_wind(wind *my_wind,int strength){
	my_wind->strength = strength;
}; 
void change_dir_wind(wind *my_wind, direction d){
	my_wind->dir = d;
}; 

#ifdef LOCAL_WIND
/*Main et Tests*/
int main(){
	//Test Initialisation
	direction dIni = N;
	wind *wIni = initialize_wind(5,dIni);
	int testIni1 = ((wIni->strength) == 5);
	int testIni2 = ((wIni->dir) == dIni);
	int resIni = testIni1 && testIni2;
	printf("Initialization test: %d\n",resIni);
	
	//Test changing parameters
	direction dChg = N;
	direction dChgNew = S;
	wind *wChg = initialize_wind(5,dChg);
	change_str_wind(wChg,6);
	int testChg1 = ((wChg->strength) == 6);
	printf("Change strength test: %d\n",testChg1);
	change_dir_wind(wChg,dChgNew);
	int testChg2 = ((wChg->dir) == dChgNew);
	printf("Change direction test: %d\n",testChg2);
	
	printf("%d",(1==1));
	return 0;
}
#endif


