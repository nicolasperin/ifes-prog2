#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float valorProduto, valorAposDesc;
    int porcDesc;
    porcDesc = 9;

    printf("Qual o valor do produto: ");
    scanf("%f", &valorProduto);

    valorAposDesc = valorProduto - (valorProduto * porcDesc/100);

    printf("Valor do produto: R$%.2f\nDesconto: %d%%\nValor final: R$%.2f\n", valorProduto, porcDesc, valorAposDesc);

    return 0;

}
