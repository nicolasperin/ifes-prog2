#include <stdio.h>
#include <stdlib.h>

int main() {
    int codigo, mais_magro = 0, mais_gordo = 0, mais_alto = 0, mais_baixo = 0;
    float altura, peso, maior_peso = -99999999, menor_peso = 99999999;
    float maior_altura = -99999999, menor_altura = 99999999;

    while(1){

    
        printf("Código: ");
        scanf("%d", &codigo);

        if (codigo <= 0) {
            break;
        }

        printf("Altura: ");
        scanf("%f", &altura);

        printf("Peso: ");
        scanf("%f", &peso);

        if (altura > maior_altura) {
            maior_altura = altura;
            mais_alto = codigo;
        }
        if (altura < menor_altura) {
            menor_altura = altura;
            mais_baixo = codigo;
        }
        if (peso > maior_peso) {
            maior_peso = peso;
            mais_gordo = codigo;
        }
        if (peso < menor_peso) {
            menor_peso = peso;
            mais_magro = codigo;
        }

    }
    if (mais_alto == 0) {
        printf("Nenhum dado válido inserido!\n");
    } else {
        printf("\nMais alto:\nCódigo: %d\nAltura: %.2fm\n\n", mais_alto, maior_altura);
        printf("Mais baixo:\nCódigo: %d\nAltura: %.2fm\n\n", mais_baixo, menor_altura);
        printf("Mais gordo:\nCódigo: %d\nPeso: %.2fkg\n\n", mais_gordo, maior_peso);
        printf("Mais magro:\nCódigo: %d\nPeso: %.2fkg\n", mais_magro, menor_peso);
    }

    return 0;
}