#include <stdio.h>
#include <stdlib.h>

int main() {
    int matricula;
    int cont_DB = 0, cont_DR = 0, cont_DI = 0;
    int cont_mulheres = 0, cont_homens = 0, cont_alunos = 0;
    int cont_DB_homens = 0, cont_DB_mulheres = 0;
    int cont_DR_homens = 0, cont_DR_mulheres = 0;
    int cont_DI_homens = 0, cont_DI_mulheres = 0;
    float nota, soma_notas = 0, media_notas;
    float porc_DB, porc_DR, porc_DI;
    float porc_DB_homens, porc_DR_homens, porc_DI_homens;
    float porc_DB_mulheres, porc_DR_mulheres, porc_DI_mulheres;
    char sexo;

    while (1) {

        printf("Matrícula: ");
        scanf("%d", &matricula);

        if (matricula <= 0){
            break;
        }


        printf("Nota (0 a 100): ");
        scanf("%f", &nota);

        while ((nota < 0) || (nota > 100)){
            
            printf("Nota inválida!\nNota (0 a 100): ");
            scanf("%f", &nota);

        }

        printf("Sexo (M/F): ");
        scanf(" %c", &sexo);

        while ((sexo != 'f') && (sexo != 'F') && (sexo != 'm') && (sexo != 'M')) {
            printf("Sexo inválido!\nSexo (M/F): ");
            scanf(" %c", &sexo);
        }

        if (sexo == 'f' || sexo == 'F') {
            
            cont_mulheres += 1;
            if (nota >= 80) {
                cont_DB_mulheres += 1;
            } else if (nota >= 60) {
                cont_DR_mulheres += 1;
            } else {
                cont_DI_mulheres += 1;
            }

        } else {
            cont_homens += 1;
            if (nota >= 80){
                cont_DB_homens += 1;
            } else if (nota >= 60){
                cont_DR_homens += 1;
            } else {
                cont_DI_homens += 1;
            }

        }

        
        if (nota >= 80){
            cont_DB += 1;
        } else if (nota >= 60){
            cont_DR += 1;
        } else {
            cont_DI += 1;
        }

        soma_notas += nota;

    }

    cont_alunos = cont_homens + cont_mulheres;

    if (cont_alunos > 0) {
        media_notas = soma_notas / cont_alunos;
        porc_DB = (float)cont_DB / cont_alunos;
        porc_DR = (float)cont_DR / cont_alunos;
        porc_DI = (float)cont_DI / cont_alunos;

        porc_DB_homens = cont_homens ? (float)cont_DB_homens / cont_homens : 0;
        porc_DR_homens = cont_homens ? (float)cont_DR_homens / cont_homens : 0;
        porc_DI_homens = cont_homens ? (float)cont_DI_homens / cont_homens : 0;

        porc_DB_mulheres = cont_mulheres ? (float)cont_DB_mulheres / cont_mulheres : 0;
        porc_DR_mulheres = cont_mulheres ? (float)cont_DR_mulheres / cont_mulheres : 0;
        porc_DI_mulheres = cont_mulheres ? (float)cont_DI_mulheres / cont_mulheres : 0;

        printf("\nExistem %d homens na turma", cont_homens);
        printf("\nExistem %d mulheres na turma", cont_mulheres);
        printf("\nA média da turma é %.2f", media_notas);
        printf("\nExistem %d alunos DB na turma", cont_DB);
        printf("\nExistem %d alunos DR na turma", cont_DR);
        printf("\nExistem %d alunos DI na turma", cont_DI);
        printf("\n%.0f%% alunos DB na turma", porc_DB * 100);
        printf("\n%.0f%% alunos DR na turma", porc_DR * 100);
        printf("\n%.0f%% alunos DI na turma", porc_DI * 100);
        printf("\n%.0f%% homens DB na turma", porc_DB_homens * 100);
        printf("\n%.0f%% homens DR na turma", porc_DR_homens * 100);
        printf("\n%.0f%% homens DI na turma", porc_DI_homens * 100);
        printf("\n%.0f%% mulheres DB na turma", porc_DB_mulheres * 100);
        printf("\n%.0f%% mulheres DR na turma", porc_DR_mulheres * 100);
        printf("\n%.0f%% mulheres DI na turma", porc_DI_mulheres * 100);
    } else {
        printf("\nNenhum aluno cadastrado.\n");
    }

    return 0;

}