#include <math.h>

struct aluno
{
    unsigned cod;
    char nome[41];
    TData nas;
    float ap1;
    float ap2;
};
typedef struct aluno TAluno;

void gere_nome(char *nom)
{
    int rs1, rs2;
    char nomes[][15] = {"Gabriel","Ricardo","Priscila","M\xa0rcia","Marcelo","S\x82rgio",
         "Felipe","Larissa","Tiago","Pedro","Carlos","Lorena","Aline","Gabriela","M\xa0rcio"};
    char sobreN[][15] = {"Oliveira","Silva","Sales","Oliveira","Lima","Ribeiro","Alves",
        "Santos","Soares","Souza","Lopes","Gomes","Bezerra","Araujo","Barreto","Pereira",
        "Menezes","Moreira"};

    strcpy(nom, "");
    strcat(nom, nomes[rand()%15]);
    strcat(nom," ");
    rs1 = rand()%18;
    strcat(nom, sobreN[rs1]);
    strcat(nom," ");
    rs2 = rand()%18;
    while(rs1 == rs2)
        rs2 = rand()%18;
    strcat(nom, sobreN[rs2]);
}

TAluno gere_aluno(unsigned cod)
{
    TAluno alu;
    alu.cod = cod;
    gere_nome(alu.nome);
    alu.nas.dia = 1 + rand()%28;
    alu.nas.mes = 1 + rand()%12;
    alu.nas.ano = 1990 + rand()%21;
    alu.ap1 = (50 + rand()%51) / 10.0;
    alu.ap2 = (50 + rand()%51) / 10.0;
    return alu;
}

float media(TAluno alu)
{
    float m = (2*alu.ap1 + 3*alu.ap2) / 5;
    return floor(10*m) / 10.0;
}

void mostre_aluno(TAluno alu)
{
    printf("%06u %-30s %02d/%02d/%d %5.1f %5.1f %5.1f",alu.cod, alu.nome,
           alu.nas.dia, alu.nas.mes, alu.nas.ano, alu.ap1, alu.ap2, media(alu));
}

int cmp_cod(const void *a, const void *b)
{
    TAluno *aa = (TAluno *) a;
    TAluno *ab = (TAluno *) b;
    return aa->cod - ab->cod;
}

int cmp_nome(const void *a, const void *b)
{
    TAluno *aa = (TAluno *) a;
    TAluno *ab = (TAluno *) b;
    return strcmp(aa->nome, ab->nome);
}

int cmp_nasc(const void *a, const void *b)
{
    TAluno *aa = (TAluno *) a;
    TAluno *ab = (TAluno *) b;
    return cmp_data(&ab->nas, &aa->nas);
}

int cmp_media(const void *a, const void *b)
{
    TAluno *aa = (TAluno *) a;
    TAluno *ab = (TAluno *) b;
    if(media(*aa) > media(*ab))
        return -1;
    else
        if(media(*aa) < media(*ab))
            return 1;
        else
            return 0;
}




