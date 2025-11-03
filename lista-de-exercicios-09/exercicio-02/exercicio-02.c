#include <stdio.h>
#include <stdlib.h>

#define MESES 12
#define MOTORES 2

typedef struct {
    int motor1;
    int motor2;
} ProducaoMensal;

typedef struct {
    float custoUnitario;
    float lucroUnitario;
} Motor;

typedef struct {
    float custoTotal;
    float lucroTotal;
    float receita;
} RelatorioMensal;

void lerProducao(FILE *arquivo, ProducaoMensal producao[]) {
    for (int i = 0; i < MESES; i++) {
        fscanf(arquivo, "%d %d", &producao[i].motor1, &producao[i].motor2);
    }
}

void lerMotores(FILE *arquivo, Motor motores[]) {
    for (int i = 0; i < MOTORES; i++) {
        fscanf(arquivo, "%f %f", &motores[i].custoUnitario, &motores[i].lucroUnitario);
    }
}

void calcularRelatorio(const ProducaoMensal producao[], const Motor motores[], RelatorioMensal relatorio[]) {
    for (int i = 0; i < MESES; i++) {
        relatorio[i].custoTotal =
            producao[i].motor1 * motores[0].custoUnitario +
            producao[i].motor2 * motores[1].custoUnitario;

        relatorio[i].lucroTotal =
            producao[i].motor1 * motores[0].lucroUnitario +
            producao[i].motor2 * motores[1].lucroUnitario;

        relatorio[i].receita = relatorio[i].lucroTotal - relatorio[i].custoTotal;
    }
}

void salvarRelatorio(FILE *arquivo, const RelatorioMensal relatorio[]) {
    fprintf(arquivo, "CUSTO\tLUCRO\tRECEITA\n");
    float custoTotal = 0, lucroTotal = 0, receitaTotal = 0;
    for (int i = 0; i < MESES; i++) {
        fprintf(arquivo, "%.2f\t%.2f\t%.2f\n",
                relatorio[i].custoTotal,
                relatorio[i].lucroTotal,
                relatorio[i].receita);
        custoTotal += relatorio[i].custoTotal;
        lucroTotal += relatorio[i].lucroTotal;
        receitaTotal += relatorio[i].receita;
    }
    fprintf(arquivo,"\nCUSTO TOTAL ANUAL: %.2f\n", custoTotal);
    fprintf(arquivo, "LUCRO TOTAL ANUAL: %.2f\n", lucroTotal);
    fprintf(arquivo, "RECEITA TOTAL ANUAL: %.2f", receitaTotal);
}


int main() {
    FILE *arquivoProducao = fopen("../ex2_producao.txt", "r");
    FILE *arquivoVendas = fopen("../ex2_vendas.txt", "r");
    FILE *arquivoSaida = fopen("output.txt", "w");

    if (!arquivoProducao || !arquivoVendas || !arquivoSaida) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    ProducaoMensal producao[MESES];
    Motor motores[MOTORES];
    RelatorioMensal relatorio[MESES];

    lerProducao(arquivoProducao, producao);
    lerMotores(arquivoVendas, motores);
    calcularRelatorio(producao, motores, relatorio);
    salvarRelatorio(arquivoSaida, relatorio);

    fclose(arquivoProducao);
    fclose(arquivoVendas);
    fclose(arquivoSaida);

    return 0;
}
