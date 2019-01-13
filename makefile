default: server client

all: test_boat test_wind test_rock test_funcmatch test_ocean server client 


#--------------------------------------------------------------
# Client & Server object files and executables

client: client.o network_tools.o ocean.o funcmatch.o
	gcc client.o network_tools.o ocean.o funcmatch.o boat.o wind.o rock.o -o client -Wall -Wextra

server: server.o network_tools.o ocean.o funcmatch.o boat.o wind.o rock.o
	gcc server.o network_tools.o funcmatch.o ocean.o boat.o wind.o rock.o -o server -Wall -Wextra
	
client.o: client.c client.h network_tools.o ocean.o
	gcc -c client.c

server.o: server.c server.h network_tools.o ocean.o
	gcc -c server.c

#--------------------------------------------------------------
# Tests for the different structures we are using

test_boat: boat.c
	gcc -D LOCAL_BOAT boat.c -o test_boat

test_wind: wind.c
	gcc -D LOCAL_WIND wind.c -o test_wind

test_rock: rock.c
	gcc -D LOCAL_ROCK rock.c -o test_rock 

test_funcmatch: funcmatch.c
	gcc -D LOCAL_FUNCMATCH funcmatch.c -o test_funcmatch 

test_ocean: ocean.c rock.c wind.c boat.c
	gcc -D LOCAL_OCEAN ocean.c rock.c wind.c boat.c -o test_ocean 

#--------------------------------------------------------------
# Object files for all the structure non-network related

ocean.o: ocean.c ocean.h rock.o wind.o boat.o
	gcc -c ocean.c 

wind.o: wind.c wind.h
	gcc -c wind.c

boat.o: boat.c boat.h
	gcc -c boat.c

funcmatch.o: funcmatch.h funcmatch.c
	gcc -c funcmatch.c

#--------------------------------------------------------------
# Object files for all the structure network related

network_tools.o: network_tools.c network_tools.h 
	gcc -c network_tools.c

rock.o: rock.c rock.h
	gcc -c rock.c

#--------------------------------------------------------------
# Cleaning the object files and the executables
clean:
	rm -rf *.o server client test_boat test_wind test_rock



