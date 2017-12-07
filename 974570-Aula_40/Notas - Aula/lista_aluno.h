#define MAX 100

struct alunos
{
    unsigned nal;
    TAluno alunos[MAX];
};
typedef struct alunos TLisAlu;

void insere_aluno(TLisAlu *lis, TAluno val)
{
    lis->alunos[lis->nal] = val;
    lis->nal++;
}

void gere_lis_alu(TLisAlu *lis, int nal)
{
    int i;
    for(i=1; i<=nal; i++)
        insere_aluno(lis, gere_aluno(i));
}

void mostre_lis_alu(TLisAlu *lis)
{
    int i;
    printf("------ ------------------------------ ---------- ----- ----- -----\n");
    printf("C%cDIGO NOME                           DATA NASC   AP1   AP2  M%cDIA\n",224,144);
    printf("------ ------------------------------ ---------- ----- ----- -----\n");
    for(i=0; i<lis->nal; i++)
    {
        mostre_aluno(lis->alunos[i]);
        printf("\n");
    }
}

