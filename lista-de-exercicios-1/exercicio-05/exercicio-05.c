#include <stdio.h>
#include <stdlib.h>

int main(){

    float tempCelsius, tempFahrenheit;

    printf("Informe a temperatura em centígrados(Celsius): ");
    scanf("%f", &tempCelsius);

    tempFahrenheit = (9 * tempCelsius + 160)/5;
    printf("Temperatura em Celsius: %.2f°C\nTemperatura em Fahrenheit: %.2f F\n", tempCelsius, tempFahrenheit);

    return 0;

}