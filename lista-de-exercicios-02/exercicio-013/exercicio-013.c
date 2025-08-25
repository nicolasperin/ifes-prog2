#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int codigo, qtd, desc = 0;
    float valorUnitario = 0, valorDescontado = 0, valorFinal = 0, valorFinalAposDesconto = 0;

    printf("Informe o código do produto: ");
    scanf("%d", &codigo);

    printf("Informe a quantidade do produto: ");
    scanf("%d", &qtd);

    if (codigo <= 0){
        printf("Código inválido! O código deve ser maior que 0\n");
        return 1;
    } else if (codigo <= 10) {
        valorUnitario = 10;
    } else if (codigo <= 20) {
        valorUnitario = 15;
    } else if (codigo <= 30) {
        valorUnitario = 20;
    } else if (codigo <= 40) {
        valorUnitario = 30;
    } else {
        printf("Código inválido!\n");
        return 1;
    }

    valorFinal = valorUnitario * qtd;

    if (valorFinal > 500){
        desc = 15;
    } else if (valorFinal >= 250) {
        desc = 10;
    } else {
        desc = 5;
    }

    valorDescontado = valorFinal * ((float)desc / 100);
    valorFinalAposDesconto = valorFinal - valorDescontado;

    printf("Valor do produto: R$%.2f\n", valorUnitario);
    printf("Valor final: R$%.2f\n", valorFinal);
    printf("Desconto: %d%%\nValor descontado: R$%.2f\n", desc, valorDescontado);
    printf("Valor final após desconto: R$%.2f\n", valorFinalAposDesconto);

    return 0;
}