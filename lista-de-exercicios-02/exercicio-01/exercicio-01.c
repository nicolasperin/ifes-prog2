#include <stdio.h>
#include <stdlib.h>

int main(){

    float num1, num2, soma;
    
    printf("Informe o primeiro número: ");
    scanf("%f", &num1);

    printf("Informe o segundo número: ");
    scanf("%f", &num2);

    soma = num1 + num2;

    if (soma > 20){
        soma += 8;
    } else {
        soma += 5;
    }

    printf("Saída: %.2f\n", soma);

    return 0;

}