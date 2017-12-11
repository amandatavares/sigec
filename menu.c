#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "data.h"

char menu_principal()
{
    printf("  1 - Vender itens\n");
    printf("  2 - Comprar itens\n");
    printf("  3 - Lista de produtos\n");
    printf("  4 - Relatórios\n");
    printf("  0 - Sair do aplicativo\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}

char menu_listagem()
{
    printf("  1 - Ordenados pelo c%cdigo\n",162);
    printf("  2 - Ordenados pela descri%c%cco\n",128,199);
    printf("  3 - Pr%cximos ao vencimento\n",162);
    printf("  4 - Produtos com baixo estoque\n");
    printf("  0 - Voltar ao menu principal\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}

char menu_relatorio()
{
    printf("  1 - Compras entre datas\n");
    printf("  2 - Vendas m%cs\n",136);
    printf("  3 - Gastos m%cs\n",136);
    printf("  4 - Produtos vencidos\n",130);
    printf("  0 - Voltar ao menu principal\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}

int main()
{
    srand(time(NULL));


    while(1) {
        printf("**********************************************************\n");
        printf("* SIGEC - SISTEMA DE GERENCIAMENTO E CONTROLE DE ESTOQUE *\n");
        printf("**********************************************************\n");

        op = menu_principal();
        printf("\n");
        if(op == '0')
            break;
        switch(op)
        {
            case '1':
                while(1) {
                    op2 = menu_listagem();
                    if(op2 == '0')
                        break;
                    switch(op2)
                    {
                        case '1':
                            printf("codigo\n");
                            qsort(la.alunos, la.nal, sizeof(TAluno), cmp_cod);
                            mostre_lis_alu(&la);
                            break;
                        case '2':
                            printf("nome\n");
                            qsort(la.alunos, la.nal, sizeof(TAluno), cmp_nome);
                            mostre_lis_alu(&la);
                            break;
                        case '3':
                            printf("idade\n");
                            qsort(la.alunos, la.nal, sizeof(TAluno), cmp_nasc);
                            mostre_lis_alu(&la);
                            break;
                        case '4':
                            printf("media\n");
                            qsort(la.alunos, la.nal, sizeof(TAluno), cmp_media);
                            mostre_lis_alu(&la);
                            break;
                        default:
                            printf("lai vai");
                    }
                }
                break;
            case '2':
                printf("Nome: ");
                alu.cod = pro_cod++;
                fflush(stdin);
                gets(alu.nome);
                alu.nas = le_data();
                alu.ap1 = 11.0;
                alu.ap2 = 11.0;
                insere_aluno(&la, alu);
                break;
            case '3':
                break;
            default:
                printf("Lesado\n\n");
        }
        printf("\n\n");
    }

    return 0;
}
