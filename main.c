#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ncurses.h>
#include "mostra_produtos.h"
#include "compra_produto.h"

// Made with ♥ by Amanda Tavares
// Esse programa foi feito na plataforma Debian, pode haver conflito de dependências

char menu_principal()
{
  // printf("  1 - Vender produto\n");
  printf("  2 - Comprar produto\n");
  printf("  3 - Listar produtos\n");
  printf("  4 - Inserir novo produto\n");
  printf("  5 - Relatórios\n");
  printf("  0 - Sair do aplicativo\n\n");
  printf("  ESCOLHA UM OP\u00c7\u00c3O: ");
  return getchar();
}

char menu_listagem()
{
  printf("  1 - Ordenados pelo c\u00f3digo\n");
  printf("  2 - Ordenados pela descri\u00e7\u00e3o\n");
  printf("  3 - Pr\u00f3ximos ao vencimento\n");
  printf("  4 - Produtos com baixo estoque\n");
  printf("  0 - Voltar ao menu principal\n\n");
  printf("  ESCOLHA UM OP\u00c7\u00c3O: ");
  return getchar();
}

char menu_relatorio()
{
  printf("\n  1 - Compras entre duas datas\n");
  // printf("  2 - Vendas m\u00eas\n");
  printf("  3 - Gastos m\u00eas\n");
  printf("  4 - Produtos vencidos\n");
  printf("  0 - Voltar ao menu principal\n\n");
  printf("  ESCOLHA UM OP\u00c7\u00c3O: ");
  return getchar();
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

    op = menu_principal();
    printf("\n");
    if(op == '0')
    break;
    // system("clear");
    switch(op) {
      // vender produto para as massas
      case '1':
      break;

      // comprar produto do fornecedor
      case '2':
      insere_prod_compra(&list_comp, &list, list);
      break;

      // listar produtos
      case '3':
      while(1) {
        op2 = menu_listagem();
        if(op2 == '0')
        break;
        // system("clear");
        switch(op2) {
          case '1':
          printf("\n\t\t%3sProdutos ordenados pelo c\u00F3digo%3s\n","\u05C0","\u05C0");
          qsort(list.itens, list.ni, sizeof(TItem), comp_cod);
          mostre_lista_prods(&list);

          break;
          case '2':
          printf("\n\t\t%3sProdutos ordenados pela descri\u00e7\u00e3o%3s\n","\u05C0","\u05C0");
          qsort(list.itens, list.ni, sizeof(TItem), comp_nome);
          mostre_lista_prods(&list);
          break;

          case '3':
          printf("\n\t\t%3sProdutos pr\u00F3ximos ao vencimento%3s\n","\u05C0","\u05C0");
          qsort(list.itens, list.ni, sizeof(TItem), comp_cod);
          mostra_produtos_vencendo(&list);
          break;

          case '4':
          printf("\n\t\t%3sProdutos em baixo estoque%3s\n","\u05C0","\u05C0");
          // qsort(list.itens, list.ni, sizeof(TItem), comp_quantidade);
          // mostre_lista_prods(&list);
          mostra_prod_acabando(&list);
          break;

          // case '3':
          // printf("\n\t\t%2sMERCADORIAS EM ORDEM POR PRE%sO%s\n","\u05C0",128,"\u05C0");
          // qsort(list.itens, list.ni, sizeof(TItem), comp_preco);
          // mostre_lista_prods(&list);
          // break;

          default:
          break;
          // printf("Lai vai, escolhe uma opção do menu, rapaz!");
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
        // system("clear");
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
          printf("\n\t\t%2sProdutos vencidos \u2502 \n","\u05C0");
          qsort(list.itens, list.ni, sizeof(TItem), comp_cod);
          mostra_produtos_vencidos(&list);
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
