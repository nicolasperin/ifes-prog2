#include <stdio.h>
#include <stdlib.h>

int main(){

    int idade;

    printf("Informe a idade: ");
    scanf("%d", &idade);

    if ((idade >= 16 && idade < 18) || idade >= 65){
        printf("Eleitor facultativo\n");
    } else if (idade >= 18 && idade < 65){
        printf("Eleitor obrigatório\n");
    } else if (idade > 0){
        printf("Não eleitor\n");
    } else {
        printf("Idade inválida\n");
    }

    return 0;

}