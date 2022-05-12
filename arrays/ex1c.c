#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int *oddlist=malloc(sizeof(int)*((n+1)/2));
    int j=0;
    for(int i=1; i<n+1; i++)
    {
        if(i%2 != 0)
        {
            oddlist[j]=i;
            j++;
        }
    }
    for(int i=0; i<((n+1)/2); i++)
        printf("%d ", oddlist[i]);
        
}
