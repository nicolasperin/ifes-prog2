#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX 100

int gerarNumAleatorio(){
    return ( rand() % 1000) + 1;
}
 

int existeNumeroRepetido(int *vetor, int num, int qtd){

    int i;
    for(i = 0; i < qtd; i++){
        if (vetor[i] == num) {
            return 1;
        }
    }

    return 0;
    
}
void adicionarNoVetor(int *vetor, int *qtd){

    int i;
    for (i = 0; i < 100; i++){
        do {
            vetor[*qtd] = gerarNumAleatorio();
        } while (existeNumeroRepetido(vetor, vetor[*qtd], *qtd) == 1);
        (*qtd)++;
    }

}


void printarVetor(int *vetor, int qtd){
    
    int i;
    for (i = 0; i < qtd; i++){
        printf("%d ", vetor[i]);
    }

}


int main(){
    
    srand( (unsigned)time(NULL) );
    
    int vetor[MAX];

    int qtd = 0;

    adicionarNoVetor(vetor, &qtd);
    printf("Vetor com números aleatórios:\n");
    printarVetor(vetor, qtd);
    
    return 0;
}