#include <stdio.h>
#include <stdlib.h>

int main(){

    float nota1, nota2, nota3, media;

    printf("Informe a nota: ");
    scanf("%f", &nota1);

    printf("Informe a nota: ");
    scanf("%f", &nota2);

    printf("Informe a nota: ");
    scanf("%f", &nota3);

    media = nota1 + nota2 + nota3 / 3;

    if (media >= 7){
        printf("Aprovado\n");
    } else if (media >= 3){
        printf("Prova final\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;

}