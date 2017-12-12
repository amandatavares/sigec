struct item
{
 unsigned cod;
 char desc[70];
 unsigned qtd;
 TData valido;
 float preco_venda;
};
typedef struct item TItem;
// TItem estoque[20];

void cadastrar(){
  TItem i;
  printf("Codigo:    ");
  scanf("%03d",&i.cod);
  // __fpurge(stdin);
  printf("Descriçao:   ");
  scanf("%s",&i.desc);
  // __fpurge(stdin);
  printf("Quantidade: ");
  scanf("%04d",&i.qtd);
  // __fpurge(stdin);
  printf("Validade: ");
  scanf("%02d/%02d/%d",&i.valido.dia,&i.valido.mes,&i.valido.ano);
  // __fpurge(stdin);
  printf("Preço de venda: ");
  scanf("%f",&i.preco_venda);
  // __fpurge(stdin);


  // test save on array
  // for(i=0; i<20; i++) {
  //     estoque[i].cod = 0;
  //     strcpy(estoque[i].desc, "NULL");
  //     estoque[i].qtd = 0;
  //     strcpy(estoque[i].valido, "NULL");
  //     estoque[i].preco_venda = 0.0;
  // }
  //

  FILE *fp;

  if((fp = fopen("produtos.txt", "a")) == NULL) /* Abre arquivo binário para escrita */
  {
    printf("Erro na abertura do arquivo");
    exit(1);
  }
  if(!fprintf(fp,"%-12d%-12s%-12d%02d/%02d/%-12d %-12f\n",i.cod,i.desc,i.qtd,i.valido.dia,i.valido.mes,i.valido.ano,i.preco_venda) )     /* Escreve a variável pi */
    printf("Erro na escrita do arquivo");
  fclose(fp);
  return;
}

void lista_por_cod(){
  FILE *fp;
  int lines = 0;
  char ch[70];

  if((fp = fopen("produtos.txt", "r")) == NULL) /* Abre arquivo binário para escrita */
  {
    printf("Erro na abertura do arquivo");
    exit(1);
  }
  printf("----------------------------------------------------------\n");
  printf("| Codigo | desc | Quantidade | Validade | Preco ");
  printf("\n----------------------------------------------------------\n");
  while( fgets (ch, 70, fp) != NULL ) {
    printf("%s",ch);
   }
   // printf("[%d]\n", lines);

}

// item * listar(){}
