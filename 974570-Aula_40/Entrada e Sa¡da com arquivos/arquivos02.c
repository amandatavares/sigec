#include<stdio.h>

main()
{
      FILE *fp;
      char c;
      fp = fopen("arquivo01.txt","r");
      if(!fp)
      {
             printf("Erro na abertura do arquivo");
             exit(1);
      }
      c = getc(fp);
      while(c != EOF)
      {
         printf("%c",c);
         c = getc(fp);
      }
      fclose(fp);
      getchar();
}
