#include <stdio.h>
#include <stdlib.h>

float lerPrecoProduto(float preco_produto){

    scanf("%f", &preco_produto);
    return preco_produto;

}

int lerNum(int forma_de_pagamento){

    scanf("%d", &forma_de_pagamento);
    return forma_de_pagamento;

}



int main(){

    float preco_produto, valor_final;
    int forma_de_pagamento, qtd;
    
    do {
        printf("Informe o preço do produto (o preço deve ser maior que zero): ");
        preco_produto = lerPrecoProduto(preco_produto);
    } while (preco_produto <= 0);

    do {
        printf("Qual a forma de pagamento?:\n\n1 - À vista\n2 - À prazo\n\n");
        forma_de_pagamento = lerNum(forma_de_pagamento);
    } while ((forma_de_pagamento != 1) && (forma_de_pagamento != 2));

    do {
        printf("\nInforme a quantidade do produto (A quantidade deve ser maior que zero): ");
        qtd = lerNum(qtd);
    } while (qtd <= 0);

    if (forma_de_pagamento == 1){
        preco_produto = preco_produto - (preco_produto*0,1);
    } else {
        preco_produto = preco_produto + (preco_produto*0,1);
    }

    valor_final = preco_produto * qtd;
    printf("\nO valor final da compra é R$%.2f", valor_final);

    return 0;

}