#include "Item.h"
struct LisProduto
{
    TItem itens[50];
    unsigned ni;

};

typedef struct LisProduto TListaProd;

TListaProd gera_lista()
{
    TListaProd lis;
    srand(time(NULL));
    char produtos[][51] = {"Leite Ninho", "Nutela", "Escova", "Bolacha Recheada", "Sabonete", "Vergonha na Cara"};
    float precos[]  = {2.50, 7.45, 4.40, 6.20, 7.4, 9.6};
    int i,q, d, m;
    for(i=0;i<6; i++){
    q = rand()%15;
    d = rand()%30+1;
    m = rand()%11+1;
    lis.itens[i].cod=q;
    strcpy(lis.itens[i].descricao,produtos[i]);
    lis.itens[i].quantidade = q;
    lis.itens[i].preco_venda = precos[i];
    lis.itens[i].validade.dia = d;
    lis.itens[i].validade.mes = m;
    lis.itens[i].validade.ano =2017;

    }
    lis.ni =6;
    return lis;
}

void insere_item(TListaProd *lis)
{
    char nome[51];
    printf("DIGITE O CÓDIGO DO PRODUTO:");
    scanf("%u", &lis->itens[lis->ni].cod);
    printf("\nDESCREVA O PORDUTO:");
    scanf("%s", nome);
    strcpy( lis->itens[lis->ni].descricao,nome);
    printf("\ndDIGITE A QUANTIDADE A SER CADASTRADA:");
    scanf("%u", &lis->itens[lis->ni].quantidade);
    printf("\nDIGITE O PREÇO DO PORDUTO:");
    scanf("%f", &lis->itens[lis->ni].preco_venda);
    printf("\nDIGITE UM DIA:");
    scanf("%d",&lis->itens[lis->ni].validade.dia);
    printf("\nDIGITE UM MES:");
    scanf("%d",&lis->itens[lis->ni].validade.mes);
    printf("\nDIGITE UM ANO:");
    scanf("%d", &lis->itens[lis->ni].validade.ano);

    lis->ni++;
}



void mostra_prod_pouca_quantidade(TListaProd *lis)

{
    int i,j;

    printf("%2c %s %c   %s %12c %s %c %6s %c %10s %2c\n",179 ,"COD",179 ,"PRODUTO",179 ,"QUANTIDADE",179 ,"VALOR", 179 ,"VALIDADE",179);

    for (j=0;j<lis->ni;j++)
        {
            if(lis->itens[j].quantidade <15)
            {
               printf("%2c %3.03d %c %-20s %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lis->itens[j].cod,179,
               lis->itens[j].descricao,179, lis->itens[j].quantidade,179, lis->itens[j].preco_venda,179,
               lis->itens[j].validade.dia,lis->itens[j].validade.mes, lis->itens[j].validade.ano,179);
               printf("%2c",195);



            }
        }

}

void mostre_lista_itens(TListaProd *lis)
{
    int i,j;



    printf("%2c %s %c   %s %12c %s %c %6s %c %10s %2c\n",179 ,"COD",179 ,"PRODUTO",179 ,"QUANTIDADE",179 ,"VALOR", 179 ,"VALIDADE",179);



    for(j=0; j<lis->ni; j++)
    {
        printf("%2c %3.03d %c %-20s %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lis->itens[j].cod,179,
               lis->itens[j].descricao,179, lis->itens[j].quantidade,179, lis->itens[j].preco_venda,179,
               lis->itens[j].validade.dia,lis->itens[j].validade.mes, lis->itens[j].validade.ano,179);


    }
    printf("%2c %3.03d %c %-20s %c %8u %3c %4.2f %4c %4.02d/%02d/%03d%c\n",179, lis->itens[lis->ni].cod,179,
               lis->itens[lis->ni].descricao,179, lis->itens[lis->ni].quantidade,179, lis->itens[lis->ni].preco_venda,179,
               lis->itens[lis->ni].validade.dia,lis->itens[lis->ni].validade.mes, lis->itens[lis->ni].validade.ano,179);

}

void mostra_produtos_prox_vencer(TListaProd *lis)
{
    int res;//variável que receberá o resultado da comparação entre as datas
    TData dt = dat_sis();
    int i,j;
    printf("  >>>>>>>>>>>>>>>>PRODUTOS PRESTES A VENCER!<<<<<<<<<<<<<<<<<<<\n");

    printf("%2c %s %c   %s %12c %s %c %6s %c %10s %2c\n",179 ,"COD",179 ,"PRODUTO",179 ,"QUANTIDADE",179 ,"VALOR", 179 ,"VALIDADE",179);
    for(j<0;j<lis->ni+1;j++)
    {
       res = cmp_data( &lis->itens[j].validade,&dt);
       if(res >4 && res<15)
        {

                   printf("%2c %3.03d %c %-20s %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lis->itens[j].cod,179,
                   lis->itens[j].descricao,179, lis->itens[j].quantidade,179, lis->itens[j].preco_venda,179,
                   lis->itens[j].validade.dia,lis->itens[j].validade.mes, lis->itens[j].validade.ano,179);

        }


    }
}
