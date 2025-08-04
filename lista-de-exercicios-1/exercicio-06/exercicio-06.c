#include <stdio.h>
#include <stdlib.h>

int main(){

    float tempCelsius, tempFahrenheit;

    printf("Informe a temperatura em Fahrenheit: ");
    scanf("%f", &tempFahrenheit);

    tempCelsius = (tempFahrenheit - 32) * 5/9;

    printf("Temperatura em Celsius: %.2f°C\nTemperatura em Fahrenheit: %.2f F\n", tempCelsius, tempFahrenheit);

    return 0;

}