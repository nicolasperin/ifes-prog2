#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

void trocaCaracteres(char *mensagem) {
    int i;
    for (i = 0; mensagem[i] != '\0'; i++) {
        switch(mensagem[i]) {
            case 'a': mensagem[i] = '@'; break;
            case 'e': mensagem[i] = '&'; break;
            case 'i': mensagem[i] = '$'; break;
            case 'o': mensagem[i] = '*'; break;
            case 'u': mensagem[i] = '#'; break;
            case '@': mensagem[i] = 'a'; break;
            case '&': mensagem[i] = 'e'; break;
            case '$': mensagem[i] = 'i'; break;
            case '*': mensagem[i] = 'o'; break;
            case '#': mensagem[i] = 'u'; break;
        }
    }
}

void inverteString(char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;
    char temp;
    
    while (inicio < fim) {
        temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
}


void criptografar(char *mensagem, char *resultado) {
    char string1[MAX], string2[MAX];
    int i, index_1 = 0, index_2 = 0, index_res = 0;
    int tam = strlen(mensagem);
    
    // Trocar vogais por símbolos
    trocaCaracteres(mensagem);
    
    // Separar índices pares e ímpares
    for (i = 0; i < tam; i++) {
        if (i % 2 == 0) {
            string1[index_1++] = mensagem[i];
        } else {
            string2[index_2++] = mensagem[i];
        }
    }
    
    // Adicionar o "fim" da string 
    string1[index_1] = '\0';
    string2[index_2] = '\0';
    
    inverteString(string2);
    
    // Intercalar string 1 e string 2
    i = 0;
    while (i < index_1 || i < index_2) {
        if (i < index_1) {
            resultado[index_res++] = string1[i];
        }
        if (i < index_2) {
            resultado[index_res++] = string2[i];
        }
        i++;
    }
    
    resultado[index_res] = '\0';
}

int main() {
    char mensagem[MAX], resultado[MAX];
    int opcao;
    
    printf("ESCOLHA UMA OPÇÃO\n\n");
    printf("1 - Criptografar mensagem\n");
    printf("2 - Descriptografar mensagem\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); 
    
    printf("\nDigite a mensagem: ");
    fgets(mensagem, MAX, stdin);
    
    mensagem[strcspn(mensagem, "\n")] = '\0';
    
    if (opcao == 1) {
        printf("Mensagem original: %s\n", mensagem);
        criptografar(mensagem, resultado);
        printf("Mensagem criptografada: %s\n", resultado);
    } 
    else if (opcao == 2) {
        printf("Mensagem criptografada: %s\n", mensagem);
        criptografar(mensagem, resultado);
        printf("Mensagem original: %s\n", resultado);
    } 
    else {
        printf("Opcao invalida!\n");
    }
    
    return 0;
}