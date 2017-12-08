struct item
{
 unsigned cod;
 char descricao[51];
 unsigned quantidade;
 TData validade;
 float preco_venda;
};
typedef struct item TItem;

void cadastrar(){
  TItem *i = malloc(sizeof(TItem));
  printf("Codigo:    "); scanf("%d",& i->cod);__fpurge(stdin);
  printf("Descriçao:   "); scanf("%s",&i->descricao);__fpurge(stdin);
  printf("Quantidade: "); scanf("%d",&i->quantidade);__fpurge(stdin);
  printf("Validade: "); scanf("%s",&i->validade);__fpurge(stdin);
  printf("Preço de venda: "); scanf("%f",&i->preco_venda);__fpurge(stdin);


  printf("%d\n",i->cod);
  printf("%s\n",i->descricao);
  printf("%d\n",i->quantidade);
  printf("%s\n",i->validade);
  printf("%f\n",i->preco_venda);
  // FILE *fp;
  //
  // if((fp = fopen("produtos.txt", "w")) == NULL) /* Abre arquivo binário para escrita */
  // {
  //   printf("Erro na abertura do arquivo");
  //   exit(1);
  // }
  // if(fprintf(fp,"\n%d %s %d %s",i->cod,i->descricao,i->quantidade,i->validade) != 1)     /* Escreve a variável pi */
  //   printf("Erro na escrita do arquivo");
  // fclose(fp);
}

// item * listar(){}
