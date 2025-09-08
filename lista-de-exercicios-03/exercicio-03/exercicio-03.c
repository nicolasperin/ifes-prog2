#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, qtd, num;
    int menor = 99999999;


    printf("Digite a quantidade de números a ser digitada: ");
    scanf("%d", &qtd);
    while (qtd <= 0){
        printf("Quantidade inválida!\nDigite a quantidade de números a ser digitada: ");
        scanf("%d", &qtd);
    }

    for (i = 1; i <= qtd; i++){
        printf("Digite um número: ");
        scanf("%d", &num);
        while (num <= 0){
            printf("Número inválido!\nDigite um número: ");
            scanf("%d", &num);
        }
        if(num < menor){
            menor = num;
        }   

    }

    printf("Menor número: %d", menor);

    return 0;

}