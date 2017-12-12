#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mostra_produtos.h"
#include "compra_produto.h"

char menu_principal()
{
  printf("  1 - Vender produto\n");
  printf("  2 - Comprar produto\n");
  printf("  3 - Listar produtos\n");
  printf("  4 - Inserir novo produto\n");
  printf("  5 - Relatórios\n");
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
  printf("  1 - Compras entre duas datas\n");
  printf("  2 - Vendas m%cs\n",136);
  printf("  3 - Gastos m%cs\n",136);
  printf("  4 - Produtos vencidos\n",130);
  printf("  0 - Voltar ao menu principal\n\n");
  printf("  ESCOLHA UM OP%c%cO: ",128,199);
  return getche();
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));
  printf("**********************************************************\n");
  printf("* SIGEC - SISTEMA DE GERENCIAMENTO E CONTROLE DE ESTOQUE *\n");
  printf("**********************************************************\n");
  int i;
  TData dt1, dt2;
  int v=1;
  TLisProd list;
  TItem it;

  list = seed_lista();
  TLdc list_comp;
  list_comp = seed_compra();


  char op,op2, op3;
  while(1) {

    op=menu_principal();
    printf("\n");
    if(op == '0')
    break;
    system("cls");
    switch(op) {
      // vender produto
      case '1':
      break;

      // comprar produto
      case '2':
      insere_prod_compra(&list_comp, &list, list);
      break;

      // listar produtos
      case '3':
      while(1) {
        op2 = menu_listagem();
        if(op2 == '0')
        break;
        system("cls");
        switch(op2) {
          case '1':
          printf("\n\t\t%cProdutos ordenados pelo c%cdigo%c\n",186,224,186);
          qsort(list.itens, list.ni, sizeof(TItem), comp_cod);
          mostre_lista_prods(&list);

          break;
          case '2':
          printf("\n\t\t%2cProdutos ordenados pela descrição%c\n",186,186);
          qsort(list.itens, list.ni, sizeof(TItem), comp_nome);
          mostre_lista_prods(&list);
          break;

          case '3':
          printf("\n\t\t%2cProdutos próximos ao vencimento%c\n",186,186);
          qsort(list.itens, list.ni, sizeof(TItem), comp_cod);
          mostra_produtos_vencendo(&list);
          break;

          case '4':
          printf("\n\t\t%2cProdutos em baixo estoque%c\n",186,186);
          // qsort(list.itens, list.ni, sizeof(TItem), comp_quantidade);
          // mostre_lista_prods(&list);
          mostra_prod_acabando(&list);
          break;

          // case '3':
          // printf("\n\t\t%2cMERCADORIAS EM ORDEM POR PRE%cO%c\n",186,128,186);
          // qsort(list.itens, list.ni, sizeof(TItem), comp_preco);
          // mostre_lista_prods(&list);
          // break;

          default:
          printf("Lai vai, escolhe uma opção do menu, rapaz!");
        }
      }

      break;

      // Inserir novo produto
      case '4':
      insere_prod(&list);
      break;

      // relatorios
      case '5':
      while(1)
      {
        op3 = menu_relatorio();
        system("cls");
        if(op3 == '0') {
          break;
        }
        switch(op3) {
          case '1':
          printf("Digite a primeira data\n");
          dt1 = le_data();
          printf("Digite a segunda data\n");
          dt2 = le_data();
          compras_entre_datas(list_comp, dt1, dt2);

          break;
          case '2':
          break;
          case '3':
          mostra_compras(&list_comp);
          break;
          case '4':
          break;
        }
      }
      break;

      default:
      printf("Escolha uma das opções do menu\n\n");
    } //switch
    printf("\n\n");

  // /while
  }
  return 0;
}
