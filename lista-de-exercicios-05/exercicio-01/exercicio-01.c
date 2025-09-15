#include <stdio.h>
#include <stdlib.h>

#define MAX 100 //tamanho do vetor

void adicionarNoVetor(int *vetor, int *qtd){
    int i;

    for (i = 100; i > 0; i--){
        vetor[*qtd] = i;
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

    int vetor[MAX];
    int qtd = 0;

    adicionarNoVetor(vetor, &qtd);
    
    printarVetor(vetor, qtd);

    return 0;

}