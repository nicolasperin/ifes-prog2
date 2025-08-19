#include <stdio.h>
#include <stdlib.h>

int main(){

    float quilometros, precoDias, precoKM, precoTotal;
    int dias;

    printf("O carro foi alugado por quantos dias?: ");
    scanf("%d", &dias);

    printf("Quantos quilômetros foram percorridos?: ");
    scanf("%f", &quilometros);

    precoDias = dias * 60.00;
    precoKM = quilometros * 0.15;

    precoTotal = precoDias + precoKM;

    printf("O valor do aluguel do carro ficou R$%.2f\n%d dias utilizados: R$%.2f\n%.2f Km rodados: R$%.2f\nTotal: R$%.2f", precoTotal, dias, precoDias, quilometros, precoKM, precoTotal);

    return 0;

}