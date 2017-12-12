#include <locale.h>
#include "produto.h"

struct LisProduto
{
    TItem itens[50];
    unsigned ni;

};

typedef struct LisProduto TLisProd;

TLisProd seed_lista()
{
    TLisProd lis;
    srand(time(NULL));
    char produtos[][51] = {"Chocolate po", "Barra fracionada", "MeM Confete", "5Star", "Oreo", "Limão"};
    float precos[]  = {20.0, 15.99, 4.00, 2.25, 3.69, 2.5};
    int i,q, d, m;
    for(i=0;i<6; i++){
    q = rand()%15;
    d = rand()%30+1;
    m = rand()%11+1;
    lis.itens[i].cod=q;
    strcpy(lis.itens[i].desc,produtos[i]);
    lis.itens[i].qtd = q;
    lis.itens[i].preco_venda = precos[i];
    lis.itens[i].valido.dia = d;
    lis.itens[i].valido.mes = m;
    lis.itens[i].valido.ano = 2017;

    }
    lis.ni = 6;
    return lis;
}

void insere_prod(TLisProd *lis)
{
    char nome[51];
    printf("Digite o código do produto:");
    scanf("%u", &lis->itens[lis->ni].cod);
    printf("\nDescreva o produto:");
    scanf("%s", nome);
    strcpy( lis->itens[lis->ni].desc,nome);
    printf("\nDigite a quantidade a ser cadastrada:");
    scanf("%u", &lis->itens[lis->ni].qtd);
    printf("\nDigite o preço do porduto:");
    scanf("%f", &lis->itens[lis->ni].preco_venda);
    printf("\nDigite a validade do produto (dd/mm/aaaa): ");
    scanf("%02d/%02d/%d",&lis->itens[lis->ni].valido.dia,&lis->itens[lis->ni].valido.mes,&lis->itens[lis->ni].valido.ano);

    lis->ni++;
}


// era mostra_prod_pouca_quantidade
void mostra_prod_acabando(TLisProd *lis)

{
    int i,j;

    printf("%2c %s %c   %s %12c %s %c %6s %c %10s %2c\n",179 ,"Cod",179 ,"Produto",179 ,"Quantidade",179 ,"Valor", 179 ,"Validade",179);

    for (j=0;j<lis->ni;j++)
        {
            if(lis->itens[j].qtd <15)
            {
               printf("%2c %3.03d %c %-20s %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lis->itens[j].cod,179,
               lis->itens[j].desc,179, lis->itens[j].qtd,179, lis->itens[j].preco_venda,179,
               lis->itens[j].valido.dia,lis->itens[j].valido.mes, lis->itens[j].valido.ano,179);
               printf("%2c",195);



            }
        }

}

void mostre_lista_prods(TLisProd *lis)
{
    int i,j;



    printf("%2c %s %c   %s %12c %s %c %6s %c %10s %2c\n",179 ,"Cod",179 ,"Produto",179 ,"Quantidade",179 ,"Valor", 179 ,"Validade",179);



    for(j=0; j<lis->ni; j++)
    {
        printf("%2c %3.03d %c %-20s %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lis->itens[j].cod,179,
               lis->itens[j].desc,179, lis->itens[j].qtd,179, lis->itens[j].preco_venda,179,
               lis->itens[j].valido.dia,lis->itens[j].valido.mes, lis->itens[j].valido.ano,179);


    }
    printf("%2c %3.03d %c %-20s %c %8u %3c %4.2f %4c %4.02d/%02d/%03d%c\n",179, lis->itens[lis->ni].cod,179,
               lis->itens[lis->ni].desc,179, lis->itens[lis->ni].qtd,179, lis->itens[lis->ni].preco_venda,179,
               lis->itens[lis->ni].valido.dia,lis->itens[lis->ni].valido.mes, lis->itens[lis->ni].valido.ano,179);

}

// era mostra_produtos_prox_vencer
void mostra_produtos_vencendo(TLisProd *lis)
{
    int res; //variável que receberá o resultado da comparação entre as datas
    TData dt = dat_sis();
    int i,j;
    printf("  ----------------Produtos próximos ao vencimento!-------------------\n");

    printf("%2c %s %c   %s %12c %s %c %6s %c %10s %2c\n",179 ,"Cod",179 ,"Produto",179 ,"Quantidade",179 ,"Valor", 179 ,"Validade",179);
    for(j<0;j<lis->ni+1;j++)
    {
       res = cmp_data( &lis->itens[j].valido,&dt);
       if(res >4 && res<15)
        {

                   printf("%2c %3.03d %c %-20s %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lis->itens[j].cod,179,
                   lis->itens[j].desc,179, lis->itens[j].qtd,179, lis->itens[j].preco_venda,179,
                   lis->itens[j].valido.dia,lis->itens[j].valido.mes, lis->itens[j].valido.ano,179);

        }


    }
}
