#include <stdio.h>
#include <stdlib.h>
#include "mostra_produtos.h"
#include "compra_produto.h"

char menu_principal()
{
    printf("  1 - Vender produto\n");
    printf("  2 - Comprar novo produto\n");
    printf("  3 - Listar produtos\n");
    printf("  4 - Relatórios\n");
    printf("  0 - Sair do aplicativo\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getchar();
}

char menu_listagem()
{
    printf("  1 - Ordenados pelo c%cdigo\n",162);
    printf("  2 - Ordenados pela descri%c%cco\n",128,199);
    printf("  3 - Pr%cximos ao vencimento\n",162);
    printf("  4 - Produtos com baixo estoque\n");
    printf("  0 - Voltar ao menu principal\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getchar();
}

char menu_relatorio()
{
    printf("  1 - Compras entre duas datas\n");
    printf("  2 - Vendas m%cs\n",136);
    printf("  3 - Gastos m%cs\n",136);
    printf("  4 - Produtos vencidos\n",130);
    printf("  0 - Voltar ao menu principal\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getchar();
}

int main()
{
    srand(time(NULL));
    printf("**********************************************************\n");
    printf("* SIGEC - SISTEMA DE GERENCIAMENTO E CONTROLE DE ESTOQUE *\n");
    printf("**********************************************************\n");
    int i;
    TData dt1, dt2;
    int v=1;
    TListaProd list;
    TItem it;

    list = gera_lista();
    TListComp list_comp;
    list_comp = gere_compra();


    char op,op2, op3;
    while(1) {

        op=menu_principal();
        printf("\n");
        if(op == '0')
            break;
            // system("clear");
        switch(op)
       {
           case '1':

               while(1) {

                    op2 = menu_listagem();
                    if(op2 == '0')
                        break;
                        // system("cls");


                     switch(op2)
                    {

                        case '1':

                            printf("\n\t\t%cMERCADORIAS EM ORDEM POR C%cDIGO%c\n",186,224,186);
                            qsort(list.itens, list.ni, sizeof(TItem), cmp_cod);
                            mostre_lista_itens(&list);


                            break;
                        case '2':
                            printf("\n\t\t%2cMERCADORIAS EM ORDEM POR NOME%c\n",186,186);
                            qsort(list.itens, list.ni, sizeof(TItem), cmp_nome);
                            mostre_lista_itens(&list);
                            break;

                        case '3':
                            printf("\n\t\t%2cMERCADORIAS EM ORDEM POR PRE%cO%c\n",186,128,186);
                            qsort(list.itens, list.ni, sizeof(TItem), cmp_preco);
                            mostre_lista_itens(&list);
                            break;
                        case '4':
                            printf("\n\t\t%2cMERCADORIAS EM ORDEM POR QUANTIDADE%c\n",186,186);
                            qsort(list.itens, list.ni, sizeof(TItem), cmp_quantidade);
                            mostre_lista_itens(&list);
                            break;
                        case '6':
                            qsort(list.itens, list.ni, sizeof(TItem), cmp_cod);
                            mostra_produtos_prox_vencer(&list);
                            break;
                        default:
                            printf("lai vai");
                    }
                }

               break;

            case '2':
                insere_item(&list);

                break;
            case '3':
                break;
            case '5':
                // system("cls");
                mostra_prod_pouca_quantidade(&list);

                break;

            case '6':

                while(1)

                    {

                        op3= menu_Compra();
                        // system("cls");
                        if(op3 == '0')
                        {
                            break;


                        }


                        switch(op3)
                        {

                        case '1':



                            mostra_compras(&list_comp);

                            break;
                        case '2':


                            insere_prod_compra(&list_comp, &list, list);





                            break;
                        case '3':
                            printf("DIGITE A PRIMEIRA DATA\n");
                            dt1 =le_data();
                            printf("DIGITE A SEGUNDA DATA DATA\n");
                            dt2 = le_data();
                            mostra_compras_entre_data(list_comp, dt1, dt2);
                            break;

                        }


                    }
                    break;
                    break;

            default:
                printf("Escolha uma das opcoes do menu\n\n");
        }
        printf("\n\n");



    }



    return 0;
}
