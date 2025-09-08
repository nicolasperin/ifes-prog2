#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, limite_inferior, limite_superior;

    printf("Informe o limite inferior do intervalo: ");
    scanf("%d", &limite_inferior);

    printf("Informe o limite superior do intervalo: ");
    scanf("%d",&limite_superior);
    while (limite_inferior > limite_superior){
        printf("Valor inválido!\nInforme o limite superior do intervalo: ");
        scanf("%d", &limite_superior); 
    }

    for (i = limite_inferior; i <= limite_superior; i++){
        if (i % 2 == 0){
            printf("%d ", i);
        }
    }

    return 0;
}