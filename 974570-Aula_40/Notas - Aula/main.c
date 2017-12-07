#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "data.h"
#include "aluno.h"
#include "lista_aluno.h"

char menu_principal()
{
    printf("  1 - Listar de alunos\n");
    printf("  2 - Matricular alunos\n");
    printf("  3 - Buscar pelo nome\n");
    printf("  0 - Sair do aplicativo\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}

char menu_listagem()
{
    printf("  1 - Ordenados pelo c%cdigo\n",162);
    printf("  2 - Ordenados pelo nome\n");
    printf("  3 - Ordenados pela idade\n");
    printf("  4 - Ordenados pela m%cdia\n",130);
    printf("  0 - Voltar ao menu principal\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}


int main()
{
    srand(time(NULL));
    TLisAlu la;
    TAluno alu;
    char op, op2;
    gere_lis_alu(&la, 20);
    mostre_lis_alu(&la);
    unsigned pro_cod = 21;

    while(1) {
        printf("********************************\n");
        printf("* SISTEMA DE CONTROLE DE NOTAS *\n");
        printf("********************************\n");

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











