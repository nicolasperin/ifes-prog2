#include <stdio.h>
#include <stdlib.h>

int main(){

    float n1, n2, n3, n4, n5, maior, menor, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    if (n1 > n2){
        maior = n1;
        menor = n2;
    } else {
        maior = n2;
        menor = n1;
    }
    
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    if (n3 > maior){
        maior = n3;
    } else if (n3 < menor){
        menor = n3;
    }

    printf("Digite a quarta nota: ");
    scanf("%f", &n4);

    if (n4 > maior){
        maior = n4;
    } else if (n4 < menor){
        menor = n4;
    }

    printf("Digite a quinta nota: ");
    scanf("%f", &n5);

    if (n5 > maior){
        maior = n5;
    } else if (n5 < menor){
        menor = n5;
    }

    media = (n1 + n2 + n3 + n4 + n5 - maior - menor)/3;

    printf("Maior nota: %.2f\nMenor nota: %.2f\nMédia: %.2f", maior, menor, media);

    return 0;

}