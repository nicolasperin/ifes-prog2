#include <stdio.h>
#define _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <math.h> // Para pegar o PI

int lerOpcao() {
    int op;
    printf("\n\nCALCULAR A ÁREA:\n");
    printf("1-Retângulo\n");
    printf("2-Círculo\n");
    printf("0-Sair\n");
    printf("Informe sua opção: ");
    scanf("%d", &op);

    while ((op != 0) && (op != 1) && (op != 2)){
        
        printf("\n\nOpção inválida\n");
        printf("1-Retângulo\n");
        printf("2-Círculo\n");
        printf("0-Sair\n");
        printf("Informe sua opção: ");
        scanf("%d", &op);

    }
    // VALIDAR a opção entre 0, 1 e 2
    return op;
}

float lerValor(float lado){

    scanf("%f", &lado);
    return lado;

}

float areaRetangulo(float base, float altura){

    float area; 
    area = base * altura;
    return area;

}

float areaCirculo(float raio){

    float area, raioQuadrado;
    raioQuadrado =  pow(raio, 2);
    area = M_PI * raioQuadrado;
    return area;
}

int main() {
    int opcao;
    float base, altura, area_retangulo, raio, area_circulo;
    do {
        opcao = lerOpcao();
        switch (opcao) {
            case 1:
            printf("\n\tÁREA DO RETÂNGULO\n");
            
            // Ler os dados para calcular a área do RETANGULO
            printf("Informe o tamanho da base do retângulo: ");
            base = lerValor(base);
            
            while (base <= 0){

                printf("Tamanho inválido!\nInforme o tamanho da base do retângulo: ");
                base = lerValor(base);

            }
            
            printf("Informe o tamanho da altura do retângulo: ");
            altura = lerValor(altura);
            
            while (altura <= 0){

                printf("Tamanho inválido!\nInforme o tamanho da altura do retângulo: ");
                altura = lerValor(altura);

            }
            // Chamar a função para calcular a área do RETANGULO
            area_retangulo = areaRetangulo(base, altura);
            
            // Mostrar o resultado
            printf("\n\nA área do retângulo é %.2f", area_retangulo);

            
            break;
            case 2:
            printf("\n\tÁREA DO CÍRCULO\n");

            // Ler os dados para calcular a área do CIRCULO
            printf("Informe o valor do raio do circulo: ");
            raio = lerValor(raio);
            
            while (raio <= 0){

                printf("Tamanho inválido!\nInforme o valor do raio do circulo: ");
                raio = lerValor(raio);

            }
            // Chamar a função para calcular a área do CIRCULO
            area_circulo = areaCirculo(raio);

            // Mostrar o resultado
            printf("\nA área do círculo é: %.2f", area_circulo);

            break;
    }
    } while ( opcao > 0);
    return 0;
}