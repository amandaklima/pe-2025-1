#include <stdio.h>

int main() {
    float salario , imposto , percentual;
    

    printf("=== CALCULADORA DE IMPOSTO DE RENDA ===\n");
    printf("Digite o salário bruto: R$ ");
    scanf("%f", &salario);
    
    if (salario <= 0) {
        printf("Erro: Salário deve ser maior que zero.\n");
        return 1;
    }

    if (salario <= 2112.00) {
        imposto = 0.00;
        percentual = 0.00;
        printf("\nIsento (até R$ 2.112,00)\n");
    }
    else if (salario <= 2826.65) {
        percentual = 7.5;
        imposto = (salario - 2112.00) * (percentual / 100);
        printf("\nFaixa: 7,5%% (de R$ 2.112,01 a R$ 2.826,65)\n");
    }
    else if (salario <= 3751.05) {
        percentual = 15.0;
        imposto = (salario - 2826.65) * (percentual / 100) + 69.36;
        printf("\nFaixa: 15%% (de R$ 2.826,66 a R$ 3.751,05)\n");
    }
    else if (salario <= 4664.68) {
        percentual = 22.5;
        imposto = (salario - 3751.05) * (percentual / 100) + 69.36 + 138.66;
        printf("\nFaixa: 22,5%% (de R$ 3.751,06 a R$ 4.664,68)\n");
    }
    else {
        percentual = 27.5;
        imposto = (salario - 4664.68) * (percentual / 100) + 69.36 + 138.66 + 205.57;
        printf("\nFaixa: 27,5%% (acima de R$ 4.664,68)\n");
    }
    
    
    printf("\n=== RESULTADO ===\n");
    printf("Alíquota aplicada: %.1f%%\n", percentual);
    printf("Imposto de Renda retido: R$ %.2f\n", imposto);
    
    return 0;
}