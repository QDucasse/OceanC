#include "wind.h"

/*Initializes a wind with a given position*/
wind *initialize_wind(int strength, direction d){
	wind *w = malloc(sizeof(wind)); //memory allocation of the wind structure
	w->strength = strength;
	w->dir = d;
	return w;
};

/*Changes wind parameters: strength and/or direction*/
void change_str_wind(wind *my_wind,int strength){
	my_wind->strength = strength;
}; 
void change_dir_wind(wind *my_wind, direction d){
	my_wind->dir = d;
}; 

/* String/Direction conversion */
direction strtodir(char strdir){
	direction dir;
	direction north = 1;
	direction east = 2;
	direction south = 3;
	direction west = 4;
	switch(strdir){
		case 'n':
		case 'N': 
			dir = north;
			return dir;
			break;
		case 'w':
		case 'W': 
			dir = east;
			return dir;
			break;
		case 's':
		case 'S': 
			dir = south;
			return dir;
			break;	
		case 'e':
		case 'E': 
			dir = west;
			return dir;
			break;				
	}
	return 0;	
}
char dirtostr(direction dir){
	char strdir;
	char strdirN = 'N';
	char strdirE = 'E';
	char strdirS = 'S';
	char strdirW = 'W';
	switch(dir){
		case N: 
			strdir = strdirN;
			return strdir;
			break;
		case E: 
			strdir = strdirE;
			return strdir;
			break;	
		case S: 
			strdir = strdirS;
			return strdir;
			break;	
		case W: 
			strdir = strdirW;
			return strdir;
			break;		
	}	
	return 'Q';	
}

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


