#ifndef ROCK_H
#define ROCK_H
 
typedef struct ROCK{
    int pos[2];
} rock;

//Initialize a rock with a given position
rock *initialize_rock(int x, int y);
//malloc() done here

//Add a given rock to a given ocean
void add_rock(rock *my_rock, ocean *my_ocean);

//Delete a given rock from a given ocean
void delete_rock(rock *my_rock, ocean *my_ocean);




