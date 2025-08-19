#include <stdio.h>
#include <stdlib.h>

int main(){

    float a, b, c, maior, menor, meio;

    printf("Informe um valor: ");
    scanf("%f", &a);

    printf("Informe um valor: ");
    scanf("%f", &b);

    printf("Informe um valor: ");
    scanf("%f", &c);

    if (a > b && a > c){
        maior = a;
        if (b > c){
            meio = b;
            menor = c;
        } else {
            meio = c;
            menor = b;
        }
    } else if (b > a && b > c){
        maior = b;
        if (a > c){
            meio = a;
            menor = c;
        } else {
            meio = c;
            menor = a;
        }
    } else {
        maior = c;
        if (a > b){
            meio = a;
            menor = b;
        } else {
            meio = b;
            menor = a;
        }
    }

    printf("Números em ordem decrescente: %.2f,%.2f,%.2f\n", maior, meio, menor);

    return 0;

}