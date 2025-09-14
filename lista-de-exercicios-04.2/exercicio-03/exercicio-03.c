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

int main(){

    int x, y, produto;
    

    printf("X e Y\n");
    lerValores(&x, &y);

    produto = calcularProduto(x,y);

    printf("\nProduto: %d\n", produto);

    return 0;

}