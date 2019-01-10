#ifndef ROCK_H
#define ROCK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int pos[2];
} rock;

//Initialize a rock with a given position
rock *initialize_rock(int x, int y);

#endif /* ROCK_H */
