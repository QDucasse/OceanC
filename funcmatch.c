#include "funcmatch.h"

int funcmatch(char* command, int id,ocean *oc){
	//split the string
	if (strncasecmp(command,"modif_speed ",11)==0){
		int speed = atoi(command+12);
		((oc->reg)->speeds)[id] = speed;
		return 1;
	} 
	else if (strncasecmp(command,"modif_direction",15)==0){
		direction dir = strtodir(*(command+16));
		((oc->reg)->directions)[id] = dir;
	}
	else if (strncasecmp(command,"say",3)==0){
		int i;
		char message = *(command+4); 
		for (i=0;i<7;i++){
			say(((oc->reg)->socket_desc)[i],("%d says %s", id, message));
		}
		return 1;
	}
	else if (strncasecmp(command,"display",9)==0){
		ocean_display(oc);
		return 1;
	}
	else if (strncasecmp(command,"quit",4)==0 || strncasecmp(command,"stop",4)==0){
		return 0;
	}	
	return 1;
}

#ifdef LOCAL_FUNCMATCH
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
#endif
	
	
	
	