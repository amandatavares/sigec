
struct lis_int
{
    unsigned nel;
    unsigned cap;
    int *elem;
};
typedef struct lis_int TLisInt;

TLisInt cria_lista()
{
    TLisInt res;
    res.nel = 0;
    res.cap = 10;
    res.elem = (int *) malloc(res.cap * sizeof(int));
    return res;
}

void realoca(TLisInt *lis, int tam)
{
    lis->elem = (int *) realloc(lis->elem, (lis->cap + tam)*sizeof(int));
    lis->cap += tam;
    printf("Memoria realocada para %u\n", lis->cap);
}

void mostre_lis_int(TLisInt lis)
{
    int i;
    if(lis.nel == 0)
    {
        printf("[]");
    }
    else
    {
        printf("[");
        for(i=0; i<lis.nel-1; i++)
        {
            printf("%d, ", lis.elem[i]);
        }
        printf("%d]", lis.elem[lis.nel-1]);
    }
}

void insere_lis_val(TLisInt *lis, int val)
{
    lis->elem[lis->nel] = val;
    lis->nel++;
}

int busca_lis_int(TLisInt lis, int val)
{
    int i;
    for(i=0; i<lis.nel; i++)
        if(val == lis.elem[i])
            return i;
    return -1;
}

int busca_bin(TLisInt lis, int val)
{
    int ini, fim, meio;
    ini = 0;
    fim = lis.nel-1;
    while(fim >= ini)
    {
        meio = (ini + fim) / 2;
        if(lis.elem[meio] == val)
            return meio;
        else
            if(val > lis.elem[meio])
                ini = meio + 1;
            else
                fim = meio - 1;
    }
    return -1;
}

int remove_ind(TLisInt *lis, int ind)
{
    int i, res = lis->elem[ind];
    for(i=ind; i<lis->nel-1; i++)
    {
        lis->elem[i] = lis->elem[i+1];
    }
    lis->nel--;
    return res;
}

int remove_val(TLisInt *lis, int val)
{
    int i, rb = busca_lis_int(*lis, val);
    if(rb != -1) {
        int res = lis->elem[rb];
        for(i=rb; i<lis->nel-1; i++)
        {
            lis->elem[i] = lis->elem[i+1];
        }
        lis->nel--;
        return res;
    }
    else
        return 999;
}

int conte(TLisInt lis, int val)
{
    int i, res=0;
    for(i=0; i<lis.nel-1; i++)
        if(val == lis.elem[i])
            res++;
    return res;
}

void remove_dup(TLisInt *lis)
{
    int i;
    for(i=0; i<lis->nel-1; i++)
    {
        if(conte(*lis, lis->elem[i]) > 1) {
            remove_ind(lis, i);
            i--;
        }
    }
}

int comp_int(const void *a, const void *b)
{
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}



















