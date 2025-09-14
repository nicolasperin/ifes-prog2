#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerPontos(int *x, int *y){


    printf("X: ");
    scanf("%d", &*x);

    printf("Y: ");
    scanf("%d", &*y);

}

double calcularDistancia(int x1, int y1, int x2, int y2){

    return pow(((pow((x2 - x1), 2)) + pow((y2 - y1), 2)),0.5);

}

int main(){

    int x1, y1, x2, y2;
    float distancia; 

    printf("X1 e Y1\n");
    lerPontos(&x1, &y1);

    printf("\nX2 e Y2\n");
    lerPontos(&x2, &y2);

    distancia = calcularDistancia(x1, y1, x2, y2);

    printf("\nDistância: %.2f\n", distancia);

    return 0;

}