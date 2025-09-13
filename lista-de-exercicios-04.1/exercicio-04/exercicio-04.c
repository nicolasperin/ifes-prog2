#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para os números aleatórios
// ########## JOGO DE CRAPS ###################

// Jogar os dados. O resto da divisão por 6 é um número de entre 0 e 5, por isso soma-se 1

int lancarDado(){
    return ( rand() % 6) + 1;
}

int jogarDados(){
    int d1, d2, soma;
    printf("\n\nVamos jogar os dados, pressione enter para jogar!\n");
    getchar();
    d1 = lancarDado();
    d2 = lancarDado();
    soma = d1 + d2;
    printf("Dado 1: %d\nDado 2: %d\n\n", d1, d2);
    printf("SOMA: %d\n", soma);
    printf("---------------------\n\n");
    return soma;
}
int main(){
    
    // SEMENTE DOS NUMEROS ALEATÓRIOS. Usa a hora local
    srand( (unsigned)time(NULL) );
 
    // Continue a partir daqui ...
    
    int soma = jogarDados();
    int ponto;
    printf("%d", soma);

    if ((soma == 7) || (soma == 11)){
        printf("Você ganhou!");
    } else if ((soma == 2) || (soma == 3) || (soma == 12)){
        printf("Você perdeu!");
    } else {
        ponto = soma;
        do {
            soma = jogarDados();
            if (soma == 7){
                printf("Você perdeu!");
                break;
            }
        } while (ponto != soma);
        if (soma != 7) {
            printf("Você ganhou!");
        }
    }
}

// código nojento