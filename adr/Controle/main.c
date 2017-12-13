#include <stdio.h>
#include <stdlib.h>
#include "lista_produtos.h"
#include "lista_compra.h"



char menu_principal()
{

    printf("MENU PRINCIPAL\n\n");
    printf("  1 - LISTAR PRODUTOS\n");
    printf("  2 - INSERIR NOVO PRODUTO\n");
    printf("  3 - PESQUISAR PELO CODIGO\n");
    printf("  4 - VENDER PRODUTO\n");
    printf("  5 - MOSTRAR PRODUTOS COM QUANTIDADE BAIXA\n");
    printf("  6 - COMPRAR PRODUTO\n");
    printf("  0 - SAIR DO APLICATIVO\n\n");
    printf("  ESCOLHA UMA OP%c%cO: ",128,199);
    return getchar();
}

char menu_listagem()
{

    printf("MENU DE LISTAGEM\n\n");
    printf("|1 - ORDENADOS PELO C%cDIGO|",224);
    printf(" |2 - ORDENADOS PELO NOME|");
    printf(" |3 - ORDENADOS PELO MAIOR PRECO|\n");
    printf("|4 - ORDENADOS PELO MENOR PRECO|");
    printf(" |5 - ORDENADOS PELA DATA DE VALIDADE|");
    printf("  |6 - MOSTRAR PRODUTOS PRESTES A VENCER|");
//    printf("  7 - MOSTRAR PRODUTOS FORA DO PRAZO\n");
    printf("  |0 - VOLTAR PARA O MENU PRINCIPAL|\n");
    printf("  ESCOLHA UMA OP%c%cO: ",128,199);
    return getchar();
}

char menu_Compra()
{

    printf("COMPRA PRODUTO\n\n");
    printf(" 1 - MOSTRAR ITENS COMPRADOS PELO C%cDIGO\n",224);
    printf(" 2 - COMPRAR PRODUTO\n");
    printf("3 - MOSTRAR COMPRAS ENTRE DUAS DATAS");
    printf(" 0 - VOLTAR PARA O MENU PRINCIPAL\n");
    printf("  ESCOLHA UMA OP%c%cO:\n\n ",128,199);
    return getchar();
}



int main()
{
    srand(time(NULL));
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
            system("cls");
        switch(op)
       {
           case '1':

               while(1) {

                    op2 = menu_listagem();
                    if(op2 == '0')
                        break;
                        system("cls");


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
                system("cls");
                mostra_prod_pouca_quantidade(&list);

                break;

            case '6':

                while(1)

                    {

                        op3= menu_Compra();
                        system("cls");
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
