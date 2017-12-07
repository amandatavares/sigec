#include <stdio.h>
#include <stdlib.h>

void prog_arit(int nt, float ti, float ra)
{
    int i;
    for(i=0; i<nt-1; i++)
    {
        printf("%.2f", ti);
        ti = ti + ra;
    }
    printf("%.2f\n", ti);
}

int fatorial(int num)
{
    int res = 1;
    int i;
    for(i=2; i<= num; i++)
    {
        res = res * i;
    }
    return res;
}


int main()
{
    prog_arit(5, 2.5, 0.5);
    int x = 5;
    printf("O fatorial de %d é igual a %d\n", x, fatorial(x));
    return 0;
}
