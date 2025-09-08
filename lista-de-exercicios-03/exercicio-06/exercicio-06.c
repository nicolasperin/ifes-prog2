#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, pulo, num_atual;
    num_atual = 1;
    pulo = 3;

    do{
        printf("Informe o valor de N: ");
        scanf("%d", &n);
    } while (n < 0);
    
    while (num_atual <= n){
        printf("%d ", num_atual);
        num_atual = num_atual + pulo;
        pulo += 2;
    }

    return 0;

}