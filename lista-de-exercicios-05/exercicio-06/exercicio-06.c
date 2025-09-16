#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX 100

int gerarNumAleatorio(){
    return ( rand() % 1000) + 1;
}


int pesquisar (int *vetor, int qtde, int pesq) {
    int i;
    for (i = 0; i < qtde; i++) {
        if (vetor[i] == pesq) {
    return i;
    }
}
    return -1;
}

void remover (int *vetor, int *qtde, int pos) {
    int i;
    for (i = pos; i < *qtde- 1; i++) {
        vetor[i] = vetor[i+1];
    }
    (*qtde)--;
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

void percorrerVetor(int *vetor, int *qtd, int *vetor2, int *qtd2, int *vetor3, int *qtd3){

    int i;
    int res = 0;
    for (i = 0; i < *qtd2; i++){
        res = pesquisar(vetor, *qtd, vetor2[i]);
        if (res != -1){
            remover(vetor2, qtd2, res);
            vetor3[*qtd3] = res;
            (*qtd3)++;
        }
    }

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
    int vetor2[MAX];
    int vetor3[MAX];

    int qtd = 0;
    int qtd2 = 0;
    int qtd3 = 0;

    adicionarNoVetor(vetor, &qtd);
    printf("Vetor com números aleatórios:\n");
    printarVetor(vetor, qtd);
    
    printf("\n\n");

    adicionarNoVetor(vetor2, &qtd2);
    printf("Vetor 2 com números aleatórios:\n");
    printarVetor(vetor2, qtd2);

    printf("\n\n");

    percorrerVetor(vetor, &qtd, vetor2, &qtd2, vetor3, &qtd3);
    printf("Vetor 2 com remoções:\n");
    printarVetor(vetor2, qtd2);

    printf("\n\n");

    printf("Vetor com os numeros removidos:\n");
    printarVetor(vetor3, qtd3);
    printf("\n\n");
    return 0;
}