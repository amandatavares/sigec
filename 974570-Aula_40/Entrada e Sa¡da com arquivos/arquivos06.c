#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
   char str[80];
   FILE *fp;

   if((fp = fopen("TEST","w+"))==NULL) {
      printf("O arquivo nao pode ser aberto.\n");
      exit(1);
   }

   do {
      printf("Digite uma string (CR para sair):\n");
      fgets(str,80,stdin);
      strcat(str,"\n");
      fputs(str,fp);
   } while(*str != '\n');

   rewind(fp);

   while(! feof(fp)) {
      fgets(str,79,fp);
      puts(str);
   }

   fclose(fp);
   getcharar();
}
