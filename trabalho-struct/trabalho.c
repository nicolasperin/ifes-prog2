#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INGREDIENTES 10
#define MAX_PEDIDOS 100
#define MAX_STR_LEN 100

typedef struct Lanche {
    char nomeDoLanche[100];
    float precoDoLanche;
    char ingredientes[MAX_INGREDIENTES][100];  
    int numIngredientes;
} Lanche;

typedef struct Pedido {
    int numeroDoPedido;
    char nomeCliente[100];
    int quantidade;
    Lanche lanche;
} Pedido;

void imprimirPedido(Pedido pedido) {
    printf("\nNúmero do pedido: %d", pedido.numeroDoPedido);
    printf("\nNome do cliente: %s", pedido.nomeCliente);
    printf("\nLanche: %s", pedido.lanche.nomeDoLanche);
    printf("\nPreço unitário: R$ %.2f", pedido.lanche.precoDoLanche);
    printf("\nQuantidade: %d", pedido.quantidade);
    printf("\nValor total: R$ %.2f", pedido.quantidade * pedido.lanche.precoDoLanche);
    printf("\nIngredientes:");
    for (int i = 0; i < pedido.lanche.numIngredientes; i++) {
        printf("\n - %s", pedido.lanche.ingredientes[i]);
    }
    printf("\n");
}

int lerNumeroInteiro(){
    int num;
    scanf("%d", &num);
    getchar();
    return num;
}

void lerString(char *str) {
    fflush(stdin);
    fgets(str, MAX_STR_LEN, stdin);
    str[strcspn(str, "\n")] = 0;  // Remove newline
}

int pesquisarPedido(Pedido *vetorPedidos, int totalPedidos, int numeroPedido) {
    int i;
    for (i = 0; i < totalPedidos; i++) {
        if (vetorPedidos[i].numeroDoPedido == numeroPedido) {
            return i;
        }
    }
    return -1;
}

void lerPedido(Pedido *vetorPedidos, int *totalPedidos) {
    if (*totalPedidos >= MAX_PEDIDOS) {
        printf("\nLimite de pedidos atingido!");
        return;
    }

    Pedido novoPedido;
    printf("\nNúmero do pedido: ");
    novoPedido.numeroDoPedido = lerNumeroInteiro();

    if (pesquisarPedido(vetorPedidos, *totalPedidos, novoPedido.numeroDoPedido) != -1) {
        printf("\nPedido já existe!");
        return;
    }


    printf("Nome do cliente: ");
    lerString(novoPedido.nomeCliente);

    printf("Nome do lanche: ");
    lerString(novoPedido.lanche.nomeDoLanche);

    printf("Preço do lanche: ");
    scanf("%f", &novoPedido.lanche.precoDoLanche);

    printf("Quantidade: ");
    novoPedido.quantidade = lerNumeroInteiro();

    printf("Número de ingredientes (max %d): ", MAX_INGREDIENTES);
    novoPedido.lanche.numIngredientes = lerNumeroInteiro();

    for (int i = 0; i < novoPedido.lanche.numIngredientes; i++) {
        printf("Ingrediente %d: ", i + 1);
        lerString(novoPedido.lanche.ingredientes[i]);
    }

    vetorPedidos[*totalPedidos] = novoPedido;
    (*totalPedidos)++;
    printf("\nPedido inserido com sucesso!");
}

void pesquisarPorNumeroEImprimir(Pedido * vetorPedidos, int  totalPedidos){
    
    printf("Informe o número do pedido: ");
    int numeroDoPedido = lerNumeroInteiro();

    int pesq = pesquisarPedido(vetorPedidos, totalPedidos, numeroDoPedido);

    if (pesq != -1){
        imprimirPedido(vetorPedidos[pesq]);
    } else { 
        printf("Pedido não encontrado!");
    }

    return;

}

void pesquisarPorNomeEImprimir(Pedido *vetorPedidos, int totalPedidos) {
    char nome[100];
    printf("\nDigite o nome do cliente: ");
    lerString(nome);
    
    int encontrou = 0;
    for (int i = 0; i < totalPedidos; i++) {
        if (strcmp(vetorPedidos[i].nomeCliente, nome) == 0) {
            imprimirPedido(vetorPedidos[i]);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("\nNenhum pedido encontrado!");
    }
}

void atualizar(Pedido * vetorPedidos, int totalPedidos){
    printf("Número do pedido: ");
    int num = lerNumeroInteiro();

    int pesq = pesquisarPedido(vetorPedidos, totalPedidos, num);

    if (pesq != -1){
        printf("Nova quantidade: ");
        int novaQuantidade = lerNumeroInteiro();
        vetorPedidos[pesq].quantidade = novaQuantidade;
    } else {
        printf("Pedido não encontrado!");
        return;
    }

}

void exibirPedidoMaisCaro(Pedido * vetorPedidos, int totalPedidos){
    int i = 0;
    Pedido pedidoMaisCaro;
    float maiorPreco = -1.0;

    for (i = 0; i < totalPedidos; i++){
        if ((vetorPedidos[i].lanche.precoDoLanche * vetorPedidos[i].quantidade) > maiorPreco){
            maiorPreco = vetorPedidos[i].quantidade * vetorPedidos[i].lanche.precoDoLanche;
            pedidoMaisCaro = vetorPedidos[i];
        }
    }

    imprimirPedido(pedidoMaisCaro);
}

void excluir(Pedido *vetorPedidos, int *totalPedidos) {
    printf("\nNúmero do pedido: ");
    int num = lerNumeroInteiro();

    int pesq = pesquisarPedido(vetorPedidos, *totalPedidos, num);

    if (pesq != -1) {
        for (int i = pesq; i < *totalPedidos - 1; i++) {
            vetorPedidos[i] = vetorPedidos[i + 1];
        }
        (*totalPedidos)--;
        printf("\nPedido excluído com sucesso!");
    } else {
        printf("\nPedido não encontrado!");
    }
}

void listar(Pedido *vetorPedidos, int totalPedidos) {
    if (totalPedidos == 0) {
        printf("\nNenhum pedido cadastrado!");
        return;
    }

    printf("\n=== LISTA DE PEDIDOS ===\n");
    for (int i = 0; i < totalPedidos; i++) {
        imprimirPedido(vetorPedidos[i]);
        printf("\n");
    }
}


int menu() {
	int op;
	system("@cls||clear");  // LIMPA A TELA
	printf("\n\nSISTEMA LANCHONETE\n\n");
	printf("1 - Inserir\n");
	printf("2 - Pesquisar por número\n");
	printf("3 - Pesquisar por nome\n");
	printf("4 - Atualizar\n");
	printf("5 - Maior\n");
	printf("6 - Excluir\n");
	printf("7 - Listar\n");
	printf("0 - Sair\n");
	do {
		printf("Escolha sua opção: ");
		scanf(" %d", &op);
        getchar();
	} while(op < 0 || op > 7);
	return op;
}


int main() {
	int op;
    Pedido pedidos[MAX_PEDIDOS];
    int totalPedidos = 0;
	do {
		op = menu();
		switch ( op ) {
			case 0:
				// SAIR. NÃO PRECISA FAZER NADA
				break;
			case 1:
				lerPedido(pedidos, &totalPedidos);
				break;
			case 2:
                pesquisarPorNumeroEImprimir(pedidos, totalPedidos);
                break;
			case 3:
                pesquisarPorNomeEImprimir(pedidos, totalPedidos);
                break;
			case 4:
				atualizar(pedidos, totalPedidos);
				break;
			case 5:
				exibirPedidoMaisCaro(pedidos, totalPedidos);
				break;
			case 6:
				excluir(pedidos, &totalPedidos);
				break;
			case 7:
				listar(pedidos, totalPedidos);
				break;
			default:
				printf ("\n\nOpçãoo inválida!\n\n");
		}

		//system("PAUSE");  // Windows
        getchar();
    } while (op != 0);
	
	return 0;
}
