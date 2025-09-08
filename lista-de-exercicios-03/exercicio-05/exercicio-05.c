#include <stdio.h>
#include <stdlib.h>

int main() {

    int num, fat;
    int cont = 1;

    printf("Digite um número: ");
    scanf("%d", &num);
    
    fat = 1;
    while (cont <= num){
        fat = cont * fat;
        cont++;
    }

    printf("%d", fat);

    return 0;
}