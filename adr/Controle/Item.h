#include "data.h"
struct item
{
    unsigned cod;
    char descricao[51];
    unsigned quantidade;
    TData validade;
    float preco_venda;
};
typedef struct item TItem;


/*COMPARA OS CODIGOS RETORNANDO O VALOR*/
int cmp_cod(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return aa->cod - ab->cod;
}
/*COMPARA OS NOMES DOS PRODUTOS*/
int cmp_nome(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return strcmp(aa->descricao, ab->descricao);
}
/*COMPARA A QUANTIDADE DOS PRODUTOS*/
int cmp_quantidade(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return aa->quantidade - ab->quantidade;
}
/*COMPARA OS CODIGOS RETORNANDO O VALOR*/
int cmp_preco(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return aa->preco_venda - ab->preco_venda;
}

