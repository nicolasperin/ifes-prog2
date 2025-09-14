#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerValores(int *x, int *y){


    printf("X: ");
    scanf("%d", &*x);

    printf("Y: ");
    scanf("%d", &*y);

}

int calcularProduto(int x, int y){

    int produto = 0;
    
    int i;
    for (i = 0; i < y; i++){
        produto = produto + x;
    }
    
    return produto;

}

int calcularPotencia(int x, int y){

    int potencia = x;
    
    int i;
    for (i = 1; i < y; i++){
        potencia = calcularProduto(potencia, x);
    }
    
    return potencia;

}

int main(){

    int x, y, potencia;
    

    printf("X e Y\n");
    lerValores(&x, &y);

    potencia = calcularPotencia(x,y);

    printf("\nPotência: %d\n", potencia);

    return 0;

}