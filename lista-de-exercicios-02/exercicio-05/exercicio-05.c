#include <stdio.h>
#include <stdlib.h>

int main(){

    int idade;

    printf("Informe a idade: ");
    scanf("%d", &idade);

    if (idade >= 65){
        printf("Pessoa idosa\n");
    } else if (idade >= 18){
        printf("Maior de idade\n");
    } else if (idade > 0){
        printf("Menor de idade\n");
    } else {
        printf("Idade inválida\n");
    }

    return 0;

}