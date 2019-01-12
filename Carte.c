#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "wind.h"

int main()
{
    
    FILE* conf = fopen("Config.txt","ab+");
    if (conf == NULL)
    {
        fprintf(stderr,"Could not open file");
    }
    char line[10];
    int u = 0;
    int X = 5;
    int Y = 5;
    while (fgets(line,sizeof(line),conf)!=NULL)
    {
        printf("%s",line);
    }
        
    fclose(conf);
    
    int *coordsX = malloc(sizeof(int)*8); //colonne coordonnées x
    int *coordsY = malloc(sizeof(int)*8); //colonne coordonnées y
    *coordsX = 4;
    *(coordsX+1) = 8;
    *coordsY = 4;
    *(coordsY+1) = 8;
    
    int a[2]={1,2};
    int b[2]={3,2};
    
    int i, j;
    for (i=0;i<X;i++)
    {
        for (j=0;j<Y;j++)
        {
            if (i==a[0] && j==a[1])
            {
                printf("<i>");
            }
            else if (i==b[0] && j==b[1])
            {
                printf("[M]");
            }
            else
            {
                printf("~~~");
            }
        }
    printf("\n");
    }
    
    return 0;
}
