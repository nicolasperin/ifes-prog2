#include <stdio.h>
#include <stdlib.h>


int main(){

    const int MINUTOS_PERDIDOS_POR_CIGARRO = 10;
    const int DIAS_NO_ANO = 365;

    int cigarrosFumadosPorDia, anosFumando, diasFumando, cigarrosFumadosNoTotal, minutosPerdidosFumando, horasPerdidasFumando, diasPerdidosFumando;

    printf("Quantos cigarros você fuma por dia?: ");
    scanf("%d", &cigarrosFumadosPorDia);

    printf("Você fuma há quantos anos?: ");
    scanf("%d", &anosFumando);

    diasFumando = anosFumando * DIAS_NO_ANO;
    cigarrosFumadosNoTotal = diasFumando * cigarrosFumadosPorDia;

    minutosPerdidosFumando = MINUTOS_PERDIDOS_POR_CIGARRO * cigarrosFumadosNoTotal;

    horasPerdidasFumando = minutosPerdidosFumando / 60;

    diasPerdidosFumando = horasPerdidasFumando / 24;

    printf("Você perdeu %d dias da sua vida fumando. Pare de fumar!", diasPerdidosFumando);

    return 0;

}