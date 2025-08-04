#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float valorProduto, valorAposDesc, porcDesc;

    printf("Qual o valor do produto: ");
    scanf("%f", &valorProduto);

    printf("Qual o valor do desconto em %%? (1 a 100): ");
    scanf("%f", &porcDesc);

    valorAposDesc = valorProduto - (valorProduto * porcDesc/100);

    printf("Valor do produto: R$%.2f\nDesconto: %.2f%%\nValor final: R$%.2f\n", valorProduto, porcDesc, valorAposDesc);

    return 0;

}
