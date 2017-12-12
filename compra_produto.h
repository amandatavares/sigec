#include "compra.h"
struct listacompra
{
  TCompra prod_compra[50] ;
  unsigned ncomp;
};

typedef struct listacompra TLdc;

// era gere_compra
TLdc seed_compra()
{
  // ldc = lista de compras
  TLdc ldC;
  ldC.prod_compra[0].data = dat_sis();
  ldC.prod_compra[0].cod_item= 10;
  ldC.prod_compra[0].quantidade = 200;
  ldC.prod_compra[0].preco_compra_total= 400;

  ldC.prod_compra[1].data = dat_sis();
  ldC.prod_compra[1].cod_item= 30;
  ldC.prod_compra[1].quantidade = 100;
  ldC.prod_compra[1].preco_compra_total= 200;
  ldC.ncomp = 2;
  return ldC;
}

void insere_prod_compra(TLdc *ldC, TLisProd *lisP, TLisProd lisP2)
{
    unsigned cod_comp;
    unsigned quantidadeC;
    float preco_compra;
    int res;
    TData resdata;

        printf("Digite o c%cdigo do produto:\n",224);
        scanf("%u", &cod_comp);
        insere_item(lisP);
        printf("Digite o pre%co total da compra:\n",128);
        scanf("%f", &preco_compra);
        printf("Digite a quantidade:\n");
        scanf("%u", &quantidadeC);
        ldC->prod_compra[ldC->ncomp].cod_item = cod_comp;
        ldC->prod_compra[ldC->ncomp].quantidade = quantidadeC;
        ldC->prod_compra[ldC->ncomp].preco_compra_total = preco_compra;
        ldC->prod_compra[ldC->ncomp].data = dat_sis();
        ldC->ncomp++;


}


// era mostra_compras_entre_data
void compras_entre_datas(TLdc listC, TData data1, TData data2)
{
    int j;
    int res1;
    int res2;
    int res3=0;
    for (j=0;j<listC.ncomp;j++){

            res1 = cmp_data(&data1,&listC.prod_compra[j].data);
            res2 = cmp_data(&data2,&listC.prod_compra[j].data);
            if(res1<0 && res2>0)
            {

                printf("%2c %3.03d %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, listC.prod_compra[j].cod_item
                              ,179, listC.prod_compra[j].quantidade,179, listC.prod_compra[j].preco_compra_total,179,
                       listC.prod_compra[j].data.dia,listC.prod_compra[j].data.mes, listC.prod_compra[j].data.ano,179);
                       res3 =1;
            }


    }
        if(res3==0) printf("NENHUMA COMPRA FEITA NESSE PER�ODO\n");

}

void mostra_compras(TLdc *ldC)
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


    for(j=0;j<ldC->ncomp;j++)
            {
               printf("%2c %3.03d %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, ldC->prod_compra[j].cod_item
                      ,179, ldC->prod_compra[j].quantidade,179, ldC->prod_compra[j].preco_compra_total,179,
               ldC->prod_compra[j].data.dia,ldC->prod_compra[j].data.mes, ldC->prod_compra[j].data.ano,179);
            }
}
