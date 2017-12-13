#include<stdio.h>

main()
{
      FILE *fp;
      char linha[80];
      fp = fopen("texto.txt","r");
      fgets(linha,80,fp);
      while(!feof(fp))
      {
          puts(linha);
          fgets(linha,80,fp);
      }
      fclose(fp);
      rewind(fp);
      getcharar();
}
