#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lis_int.h"


int main()
{
    int i;
    srand(time(NULL));
    TLisInt li = cria_lista();
    for(i=0; i<21; i++)
    {
        if(li.nel == li.cap)
            realoca(&li, 10);
        insere_lis_val(&li, rand()%20);
        mostre_lis_int(li);
        printf("\n");
    }

    while(li.nel > 1)
    {
        if(li.cap - li.nel > 10)
        {
            realoca(&li, -10);
        }
        printf("%d removido\n",remove_ind(&li, 0));
        mostre_lis_int(li);
        printf("\n");
    }
    printf("%d removido\n",remove_ind(&li, 0));
    mostre_lis_int(li);
//    qsort(li.elem, li.nel-1, sizeof(int), comp_int);

    return 0;
}
