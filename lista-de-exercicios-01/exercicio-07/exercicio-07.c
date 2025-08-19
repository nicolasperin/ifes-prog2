#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b, temp;
    printf("Informe um valor para a variável A (inteiro):");
    scanf("%d", &a);
    printf("Informe um valor para a variável B (inteiro):");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;

    printf("Variáveis trocadas:\nA = %d\nB = %d\n", a, b);

    return 0;

}