#ifndef FILES_H
#define FILES_H

typedef struct {
    int ID_count = 0;
	int matrice[2][10];
} registery;

//Fichier config initiale en gros
typedef struct {
    wind *w;
    //Position des rochers ?
} map;


FILE *open(char *path);

void close(FILE *file);

#endif //FILES_H