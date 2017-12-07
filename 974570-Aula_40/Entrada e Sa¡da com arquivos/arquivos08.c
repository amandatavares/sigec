#include<stdio.h>
#include<stdlib.h>

struct fracao {
   int num;
   int den;
};

main()
{
   FILE *fp;
   double dr, dw = 12.23;
   int ir, iw = 101;
   long lr, lw = 123023L;
   char sw[10] = "CEFET", sr[10];
   struct fracao fw, fr;
   fw.num = 2;
   fw.den = 3;

   if((fp = fopen("TEST","wb+"))==NULL) {
      printf("O arquivo nao pode ser aberto.\n");
      exit(1);
   }

   fprintf(fp,"%f %d %ld %s %d %d",dw,iw,lw,sw,fw.num, fw.den);

   rewind(fp);

   fscanf(fp,"%lf%d%ld%s%d%d",&dr,&ir,&lr,sr, &fr.num, &fr.den);

   printf("%f %d %ld %s %d/%d\n", dr, ir, lr, sr, fr.num, fr.den);

   fclose(fp);
   system("pause");
}

