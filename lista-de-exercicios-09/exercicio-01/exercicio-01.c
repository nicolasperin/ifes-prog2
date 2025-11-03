#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void converterMinusculas(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int pesq(char * palavra, char vetorPesquisa[][50], int tamanhoVetor){
    int i;
    char palavraTemporaria[50];

    strcpy(palavraTemporaria, palavra);
    converterMinusculas(palavraTemporaria);
    
    for (i = 0; i < tamanhoVetor; i++) {
        if (strcmp(palavraTemporaria, vetorPesquisa[i]) == 0) {
            return i;
        }
    }
    return -1; 
}

void gerarAsteriscos(char *palavra, char *resultado) {
    int i;
    int tamanho = strlen(palavra);
    
    for (i = 0; i < tamanho; i++) {
        resultado[i] = '*';
    }
    resultado[tamanho] = '\0';
}


int main(){
    FILE *arquivo_input, *arquivo_output;
    char palavrasProibidas[100][50] = {"sexo", "erótico", "golpe",
         "ladrão", "rapariga", "rebelião", "darth", "vader", "skywalker",
         "jedi", "flamengo"};
    int qtd_palavras_proibidas = 11;
    char asteriscos[50];
    char palavra[50];

    arquivo_input = fopen("../ex1_input.txt", "r");
    arquivo_output = fopen("output.txt", "w");


    while (fscanf(arquivo_input, "%s", palavra) != EOF){
        
        if (pesq(palavra, palavrasProibidas, qtd_palavras_proibidas) != -1){
            gerarAsteriscos(palavra, asteriscos);
            fprintf(arquivo_output, "%s ", asteriscos);
        } else {
            fprintf(arquivo_output, "%s ", palavra);
        }
    }


    fclose(arquivo_input);
    fclose(arquivo_output);

}