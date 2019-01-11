rock.o: rock.c rock.h
	gcc -c rock.c

wind.o: wind.c wind.h
	gcc -c wind.c

boat.o: boat.c boat.h
	gcc -c boat.c

ocean.o: ocean.c ocean.h rock.o wind.o boat.o
	gcc -c ocean.c

funcmatch.o: funcmatch.h funcmatch.c
	gcc -c funcmatch.c

network_tools.o: network_tools.c network_tools.h 
	gcc -c network_tools.c

client.o: client.c client.h network_tools.o ocean.o
	gcc -c client.c

server.o: server.c server.h network_tools.o ocean.o
	gcc -c server.c

server: server.o network_tools.o ocean.o funcmatch.o
	gcc server.o network_tools.o ocean.o funcmatch.o -o server

client: client.o network_tools.o ocean.o funcmatch.o
	gcc client.o network_tools.o ocean.o funcmatch.o -o client

test_boat: boat.o
	gcc -DLOCAL_BOAT boat.o -o test_boat

test_wind: wind.o
	gcc -DLOCAL_WIND wind.o -o test_wind

test_rock: rock.o
	gcc -DLOCAL_ROCK rock.o -o test_rock 