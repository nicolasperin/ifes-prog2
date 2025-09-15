#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void adicionarNoVetor(int *vetor, int *qtd){

    int i;
    for (i = 1; i <= 20; i++){
        if ((*qtd % 2 ) == 0){
            vetor[*qtd] = pow(i, 2);
        } else {
            vetor[*qtd] = pow(i, 3);
        }
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

    int vetor[20];
    int qtd = 0;

    adicionarNoVetor(vetor, &qtd);
    printarVetor(vetor, qtd);


    return 0;

}