#include <stdio.h>
#include <string.h>
#include "files.h"

//Opening a file
FILE *open(char *path)
{
  FILE *file;
  file = fopen(path,"ab+");
  return file;
}

//Closing a file
void close(FILE *file)
{
  fclose(file);
}

/* REGISTERY
 * The registery is used to store the IDs of the boats
 */

/* MAP
 * The map is used to store the initial configuration of our ocean
 */
  