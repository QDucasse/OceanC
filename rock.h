#ifndef ROCK_H
#define ROCK_H

typedef struct {
    int pos[2];
} rock;

//Initialize a rock with a given position
rock *initialize_rock(int x, int y);

#endif
