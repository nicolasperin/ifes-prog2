#include <stdio.h>
#include <stdlib.h>

int main(){

    float a1, r, n_termo;
    int n;

    printf("Informe a razão da PA: ");
    scanf("%f", &r);

    printf("Informe  primeiro termo: ");
    scanf("%f", &a1);

    printf("Informe o número de elementos: ");
    scanf("%d", &n);

    n_termo = a1 + (n-1) * r;

    printf("O %d° termo é %.2f\n", n,n_termo);

    return 0;

}