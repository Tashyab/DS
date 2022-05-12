#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *expl= malloc(5*sizeof(int));
    *expl=2200;
    *(expl+1)=2350;
    *(expl+2)=2600;
    *(expl+3)=2130;
    *(expl+4)=2190;
    printf("You spent %d more in feb as compared to jan.\n", expl[1]-expl[0]);
    printf("%d is your expenditure in the first quarter.\n", expl[0]+expl[1]+expl[3]);

    int *expln= realloc(expl, sizeof(int)*6);
    *(expln+5)=1980;
    expln[3]=expln[3]-200;

    for(int i=0; i<6; i++)
    {
        printf("%d ", expln[i]);
    }
}