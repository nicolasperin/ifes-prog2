#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX 20

int gerarNumAleatorio(){
    return ( rand() % 100) + 1;
}
 
void adicionarNoVetor(int *vetor, int *qtd){

    int i;
    for (i = 0; i < 20; i++){
        vetor[*qtd] = gerarNumAleatorio();
        (*qtd)++;
    }

}


void printarVetor(int *vetor, int qtd){
    
    int i;
    for (i = 0; i < qtd; i++){
        printf("%d ", vetor[i]);
    }

}

void preencherVetoresSecundarios(int *vetorPares, int *vetorImpares, int *vetor, int *qtd_pares, int *qtd_impares){

    int i;
    for (i = 0; i < MAX; i++){
        if ((vetor[i] % 2) == 0){
            vetorPares[*qtd_pares] = vetor[i];
            (*qtd_pares)++;
        } else {
            vetorImpares[*qtd_impares] = vetor[i];
            (*qtd_impares)++;
        }
    }

}


int main(){

    srand( (unsigned)time(NULL) );

    int vetor[MAX];
    int vetorImpares[MAX];
    int vetorPares[MAX];
    int qtd = 0;
    int qtd_pares = 0;
    int qtd_impares = 0;

    adicionarNoVetor(vetor, &qtd);
    printf("Vetor com números aleatórios:\n");
    printarVetor(vetor, qtd);

    printf("\n\n");
    preencherVetoresSecundarios(vetorPares, vetorImpares, vetor, &qtd_pares, &qtd_impares);
    printf("Vetor Pares: \n");
    printarVetor(vetorPares, qtd_pares);
    printf("\n\nVetor Ímpares: \n");
    printarVetor(vetorImpares, qtd_impares);
    printf("\n");

    return 0;
}