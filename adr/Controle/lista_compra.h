#include "Compra_Item.h"
struct listacompra
{
  TCompra item_compra[50] ;
  unsigned ncomp;
};

typedef struct listacompra TListComp;

TListComp gere_compra()
{
  TListComp lisC;
  lisC.item_compra[0].cod_item= 10;
  lisC.item_compra[0].data = dat_sis();
  lisC.item_compra[0].preco_compra_total= 400;
  lisC.item_compra[0].quantidade = 200;

  lisC.item_compra[1].cod_item= 30;
  lisC.item_compra[1].data = dat_sis();
  lisC.item_compra[1].preco_compra_total= 200;
  lisC.item_compra[1].quantidade = 100;
  lisC.ncomp = 2;
  return lisC;
}

void insere_prod_compra(TListComp *lisC, TListaProd *lisP, TListaProd lisP2)
{
    unsigned cod_comp;
    unsigned quantidadeC;
    float preco_compra;
    int res;
    TData resdata;

        printf("DIGITE O C%cDIGO DO PRODUTO:\n",224);
        scanf("%u", &cod_comp);
        insere_item(lisP);
        printf("DIGITE O PRE%cO TOTAL DA COMPRA:\n",128);
        scanf("%f", &preco_compra);
        printf("DIGITE A QUANTIDADE:\n");
        scanf("%u", &quantidadeC);
        lisC->item_compra[lisC->ncomp].cod_item = cod_comp;
        lisC->item_compra[lisC->ncomp].quantidade = quantidadeC;
        lisC->item_compra[lisC->ncomp].preco_compra_total = preco_compra;
        lisC->item_compra[lisC->ncomp].data = dat_sis();
        lisC->ncomp++;


}



void mostra_compras_entre_data(TListComp listC, TData data1, TData data2)
{
    int j;
    int res1;
    int res2;
    int res3=0;
    for (j=0;j<listC.ncomp;j++){

            res1 = cmp_data(&data1,&listC.item_compra[j].data);
            res2 = cmp_data(&data2,&listC.item_compra[j].data);
            if(res1<0 && res2>0)
            {

                printf("%2c %3.03d %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, listC.item_compra[j].cod_item
                              ,179, listC.item_compra[j].quantidade,179, listC.item_compra[j].preco_compra_total,179,
                       listC.item_compra[j].data.dia,listC.item_compra[j].data.mes, listC.item_compra[j].data.ano,179);
                       res3 =1;
            }


    }
        if(res3==0) printf("NENHUMA COMPRA FEITA NESSE PERÍODO\n");

}

void mostra_compras(TListComp *lisC)
{
    int i,j;

    printf("%2c",218);
    for (i=0;i<5;i++)
        printf("%c", 196);
    printf("%c", 194);
    for (i=0;i<12;i++)
        printf("%c", 196);
    printf("%c", 194);
    for (i=0;i<10;i++)
        printf("%c", 196);
    printf("%c", 194);
    for (i=0;i<13;i++)
        printf("%c", 196);

    printf("%c\n", 191);

    printf("%2c %s %c %4s %c %s %c %s %8c\n",179 ,"COD",179 ,"QUANTIDADE",179 ,"V.COMPRA", 179 ,"DATA",179);

    printf("%2c",195);
    for (i=0;i<5;i++)
        printf("%c", 196);
    printf("%c", 197);
    for (i=0;i<12;i++)
        printf("%c", 196);
    printf("%c", 197);
    for (i=0;i<10;i++)
        printf("%c", 196);
    printf("%c", 197);
    for (i=0;i<13;i++)
        printf("%c", 196);
    printf("%c\n", 180);


    for(j=0;j<lisC->ncomp;j++)
            {
               printf("%2c %3.03d %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lisC->item_compra[j].cod_item
                      ,179, lisC->item_compra[j].quantidade,179, lisC->item_compra[j].preco_compra_total,179,
               lisC->item_compra[j].data.dia,lisC->item_compra[j].data.mes, lisC->item_compra[j].data.ano,179);
            }
}

