#include <stdio.h>
#include <stdlib.h>

int main(){

    float salarioMinimo, salarioPessoa, salariosRecebidos;
    
    printf("Qual o valor do salário mínimo atualmente?: ");
    scanf("%f", &salarioMinimo);

    printf("Qual o seu salário?: ");
    scanf("%f", &salarioPessoa);

    salariosRecebidos = salarioPessoa / salarioMinimo;

    printf("\nVocê recebe %.2f salários mínimos!\n", salariosRecebidos);

    return 0;

}