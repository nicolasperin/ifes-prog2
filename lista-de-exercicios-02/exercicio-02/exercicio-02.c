#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float num, saida;

    printf("Informe o número: ");
    scanf("%f", &num);

    if (num >= 0){
        saida = sqrt(num);
    } else {
        saida = pow(num, 2);
    }

    printf("Saída: %.2f", saida);

    return 0;

}