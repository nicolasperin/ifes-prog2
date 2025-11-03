#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNOS 100
#define TAM_NOME 20

FILE *abrirArquivo(const char *nome_arquivo, const char *modo) {
    FILE *arquivo = fopen(nome_arquivo, modo);

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo: %s\n", nome_arquivo);
        exit(EXIT_FAILURE);
    }

    return arquivo;
}

int ehNumero(const char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; 
        }
    }
    return 1;
}

int main(void) {
    FILE *arquivo_input = abrirArquivo("../ex3_alunos.txt", "r");
    FILE *arquivo_leds = abrirArquivo("leds.txt", "w");
    FILE *arquivo_leter = abrirArquivo("leter.txt", "w");
    FILE *arquivo_robotica = abrirArquivo("robotica.txt", "w");

    char palavra[TAM_NOME];
    int matricula = 0;

    while (fscanf(arquivo_input, "%s", palavra) == 1) {

        if (ehNumero(palavra)) {
            matricula = atoi(palavra); 
        }

        if (strcmp(palavra, "LETER") == 0) {
            fprintf(arquivo_leter, "%d\n", matricula);
        } 
        else if (strcmp(palavra, "LEDS") == 0) {
            fprintf(arquivo_leds, "%d\n", matricula);
        } 
        else if (strcmp(palavra, "Robótica") == 0) {
            fprintf(arquivo_robotica, "%d\n", matricula);
        }
    }

    fclose(arquivo_input);
    fclose(arquivo_leds);
    fclose(arquivo_leter);
    fclose(arquivo_robotica);

    return 0;
}
