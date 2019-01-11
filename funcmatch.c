#include "funcmatch.h"

int funcmatch(char* command, int id){
	//split the string
	if (strncasecmp(command,"modif_speed ",11)==0){
		int speed = (int) (command+12);
		//oceanRegistery[id]->speed = newSpeed
		return 1;
	} 
	else if (strncasecmp(command,"modif_direction",15)==0){
		//char direction = (buf+15) (int)
		//oceanRegistery[id]->direction = newDirection
	}
	else if (strncasecmp(command,"say",3)==0){
		int i=0;
		/*
		for (i;i<7;i++){
			if(say(oceanRegistery[id][indice socket_d],("%d says %s", id, la suite de la string) 
		}
		*/
		return 1;
	}
	else if (strncasecmp(command,"display",9)==0){
		//display the ocean
		return 1;
	}
	else if (strncasecmp(command,"quit",4)==0 || strncasecmp(command,"stop",4)==0){
		return 0;
		//ptet close le socket ici aussi
	}	
	return 1;
}

int main(int argc, char *argv[]) {
	int idTest = 1;
	
	//Test FunctionMatcher "Hello"
	char testHello[] = "Hello";
	int resTestHello = funcmatch(testHello,idTest); /* with "Hello", the function matcher should return 1 */
	printf("Function matcher default case test: %d\n",resTestHello);
	
	//Test FunctionMatcher "stop"
	char testStop[] = "stop";
	int resTestStop = !funcmatch(testStop,idTest); /* with "stop", the function matcher should return 0 */
	printf("Function matcher stop case test: %d\n",resTestStop);
	
	//Test FunctionMatcher "quit"
	char testQuit[] = "quit";
	int resTestQuit = !funcmatch(testQuit,idTest); /* with "quit", the function matcher should return 0 */
	printf("Function matcher quit case test: %d\n",resTestQuit);
	
	//Test FunctionMatcher "display"
	char testDisplay[] = "display";
	int resTestDiplay = funcmatch(testDisplay,idTest); /* with "display", the function matcher should return 1 */
	printf("Function matcher display case test: %d\n",resTestDiplay);
	
	//Test FunctionMatcher "modif_speed"
	char testModSpd[] = "modif_speed";
	int resTestModSpd = funcmatch(testModSpd,idTest); /* with "modif_speed", the function matcher should return 1 */
	printf("Function matcher modif_direction case test: %d\n",resTestModSpd);
	
	//Test FunctionMatcher "modif_direction"
	char testModDir[] = "modif_direction";
	int resTestModDir = funcmatch(testModDir,idTest); /* with "modif_direction", the function matcher should return 1 */
	printf("Function matcher modif_speed case test: %d\n",resTestModDir);
}
	
	
	
	
	
	