#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float a1, q, n_termo;
    int n;

    printf("Informe a razão da PG: ");
    scanf("%f", &q);

    printf("Informe  primeiro termo: ");
    scanf("%f", &a1);

    printf("Informe o número de elementos: ");
    scanf("%d", &n);

    n_termo = a1 * pow(q,n-1);

    printf("O %d° termo é %.2f\n", n,n_termo);

    return 0;

}
