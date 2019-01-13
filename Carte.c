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
    int X, Y;
    int* RocksX = malloc(sizeof(int)*20);
    int* RocksY = malloc(sizeof(int)*20);
    while (fgets(line,sizeof(line),conf)!=NULL)
    {
        switch(u)
        {
            case 0: X=atoi(line); break;
                printf("%d",X); 
                break;
            case 1: Y=atoi(line); break;
            default:
                sscanf(line,"%d %d",RocksX+u-2,RocksY+u-2);
        }
        u++;
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
    
    int i, j, k;
    for (i=0;i<X;i++)
    {
        for (j=0;j<Y;j++)
        {
            int Found = 0;
            /* Rocher */
            for (k=0;k<u-2;k++)
            {
                if (i==*(RocksX+k) && j==*(RocksY+k))
                {
                    printf("[R]");
                    Found = 1;/*
                    printf("i=%d,j=%d,k=%d",i,j,k);*/
                }
            }
            
            /* Bateau */
            if (Found==0)
            {
                for (k=0;k<8;k++)
                {
                    if (i==*(coordsX+k) && j==*(coordsY+k))
                    {
                        printf("<i>");
                        Found = 1;
                    }
                }
            }
            
            /* Mer */
            if (Found==0)
            {
                printf("~~~");
            }
        }
    printf("\n");
    }
    
    return 0;
}
