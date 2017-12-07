#include <stdio.h>
#include <stdlib.h>

main()
{
      FILE *fp;
      char string[100];
      int i;
      fp = fopen("arquivo01.txt","w");
      if(!fp)
      {
             printf("Erro na abertura do arquivo");
             exit(1);
      }
      printf("Entre com a string a ser gravada no arquivo: ");
      fgets(string,80,stdin);
      for(i=0; string[i]; i++) putc(string[i],fp);
      fclose(fp);
}
