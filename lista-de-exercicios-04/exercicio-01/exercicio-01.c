#include <stdio.h>
#include <stdlib.h>

int lerMatricula(){
    int matricula;
    scanf("%d", &matricula);
    return matricula;
}

int validarMatricula(int matricula){

    if (matricula <= 0) {
        return 0;
    }

    return 1;

}

float lerNotaEValidar(){

    float nota; 
    printf("Nota: ");
    scanf("%f", &nota);
    
    while (nota < 0) {
        printf("Nota inválida!\nNota: ");
        scanf("%f", &nota);    
    }
    return nota;

}

int calcularSituacao(float media){
    /*
    0 = reprovado
    1 = aprovado
    2 = prova final
    */

    if (media >= 7){
        return 1;
    } else if (media >= 6){
        return 2;
    }

    return 0;
}


int main(){

    int matricula, validacao_matricula, situacao;
    float nota_1, nota_2, nota_3, media;
     
    
    do {
        printf("Matrícula: ");
        matricula = lerMatricula();

        validacao_matricula = validarMatricula(matricula);
        if (validacao_matricula == 0){
            printf("Matrícula inválida!\n");
        }
       
    } while (validacao_matricula == 0);


    nota_1 = lerNotaEValidar();
    nota_2 = lerNotaEValidar();
    nota_3 = lerNotaEValidar();


    media = (nota_1 + nota_2 + nota_3) / 3;

    situacao = calcularSituacao(media);

    if (situacao == 0){
        printf("Reprovado!");
    } else if (situacao == 1){
        printf("Aprovado!");
    } else {
        printf("Prova final");
    }

    return 0;

}