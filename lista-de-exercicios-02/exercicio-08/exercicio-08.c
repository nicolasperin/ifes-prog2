#include <stdio.h>
#include <stdlib.h>

int main(){

    int x, res;
    printf("Digite o valor de X: ");
    scanf("%d", &x);

    if (x > 3){
        res = x*x*x;
    } else if (x > 2){   
        res = x*x;
    } else if (x > 1){
        res = 2;
    } else {
        res = 1;
    }
    printf("%d\n", res);

    return 0;

}