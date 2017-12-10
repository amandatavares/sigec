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
  TItem i;
  printf("Codigo:    ");
  scanf("%03d",&i.cod);
  // __fpurge(stdin);
  printf("Descriçao:   ");
  scanf("%s",&i.descricao);
  // __fpurge(stdin);
  printf("Quantidade: ");
  scanf("%04d",&i.quantidade);
  // __fpurge(stdin);
  printf("Validade: ");
  scanf("%02d/%02d/%d",&i.validade.dia,&i.validade.mes,&i.validade.ano);
  // __fpurge(stdin);
  printf("Preço de venda: ");
  scanf("%f",&i.preco_venda);
  // __fpurge(stdin);

  FILE *fp;

  if((fp = fopen("produtos.txt", "a")) == NULL) /* Abre arquivo binário para escrita */
  {
    printf("Erro na abertura do arquivo");
    exit(1);
  }
  if(!fprintf(fp,"%d\n%s\n%d\n%02d/%02d/%d\n%f",i.cod,i.descricao,i.quantidade,i.validade.dia,i.validade.mes,i.validade.ano,i.preco_venda) )     /* Escreve a variável pi */
    printf("Erro na escrita do arquivo");
  fclose(fp);
  return;
}

// item * listar(){}
