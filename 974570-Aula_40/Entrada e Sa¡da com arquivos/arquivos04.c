#include<stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
      FILE *pf;
      char string[100];
      if((pf = fopen("texto.txt","w"))==NULL)
      {
             printf("Erro na abertura do arquivo");
             exit(1);
      }
      do
      {
             printf("\nDigite uma string. Para terminar digite <enter>: ");
             fgets(string,90,pf);
             fputs(string,pf);
             putc('\n',pf);
             if (ferror(pf))
             {
                 printf("Erro de gravação");
                 exit(1);
             }
      } while( strlen(string)>0);
      fclose(pf);
}
