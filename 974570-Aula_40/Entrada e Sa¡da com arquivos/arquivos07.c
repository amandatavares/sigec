#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fracao {
   int num;
   int den;
};

main()
{
   FILE *fp;
   double dr, dw = 12.23;
   int ir, iw = 101;
   long lr, lw = 123023;
   char sw[10] = "CEFET", sr[10];
   struct fracao fw, fr;
   fw.num = 2;
   fw.den = 3;
   
   if((fp = fopen("teste02.dat","wb+"))==NULL) {
      printf("O arquivo nao pode ser aberto.\n");
      exit(1);
   }

   fwrite(&dw,sizeof(double),1,fp);   
   fwrite(&iw,sizeof(int),1,fp);   
   fwrite(&lw,sizeof(long),1,fp);
   fwrite(sw,10,1,fp);
   fwrite(&fw,sizeof(struct fracao),1,fp);
   
   rewind(fp);
   
   fread(&dr,sizeof(double),1,fp);   
   fread(&ir,sizeof(int),1,fp);   
   fread(&lr,sizeof(long),1,fp);
   fread(sr,10,1,fp);
   fread(&fr,sizeof(struct fracao),1,fp);
   
   printf("%f %d %ld %s %d/%d\n", dr, ir, lr, sr, fr.num, fr.den);
   
   fclose(fp);
   system("pause");
}
