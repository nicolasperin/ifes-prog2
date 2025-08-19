#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;

    printf("Informe um número: ");
    scanf("%d", &num);
    
    if (num % 10 == 0){
        printf("O número é divisível por 10\n");
    } else if (num % 5 == 0){
        printf("O número é divisível por 5\n");
    } else if (num % 2 == 0){
        printf("O número é divisível por 2\n");
    }

    return 0;

}