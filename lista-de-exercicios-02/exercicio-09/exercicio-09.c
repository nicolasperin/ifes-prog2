#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int a, b, c;
    float delta, x1, x2;

    printf("Insira o valor de a: ");
    scanf("%d", &a);

    printf("Insira o valor de b: ");
    scanf("%d", &b);

    printf("Insira o valor de c: ");
    scanf("%d", &c);

    delta = b*b - 4*a*c;

    x1 = (-b + sqrt(delta))/(2 * a);
    x2 = (-b - sqrt(delta))/(2 * a);

    if (delta < 0){
        printf("Não há solução real\n");
    } else if (delta == 0){ 
        printf("Há duas soluções reais iguais:\nx1 e x2 = %.2f\n", x1);
    } else {
        printf("Há duas soluções reais diferentes:\nx1 = %.2f\nx2 = %.2f\n", x1, x2);
    }

    if (a > 0){
        printf("Concavidade voltada para cima\n");
    } else if (a == 0){
        printf("Não é uma equação de 2° grau\n");
    } else {
        printf("Concavidade voltada para baixo\n");
    }

    return 0;

}