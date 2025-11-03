#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 100
#define MAX_PROJETOS 3
#define TAM_NOME 20

typedef struct {
    int matricula;
    char projetos[MAX_PROJETOS][TAM_NOME];
} Aluno;


int main(){

    FILE *arquivo_input, *arquivo_output; 

    Aluno alunos[MAX_ALUNOS];

    int i;

    arquivo_input = fopen("ex3_alunos.txt", "r");

    return 0;

}