#include <stdio.h>
#include <string.h>

int main()
{
    int a[2] = {5,6};
    int b[2] = {8,16};
    int X = 20;
    int Y = 18;
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
