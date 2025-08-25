#include <stdio.h>

int main() {
  double salario, salarioContribuicao;

  printf("Digite o salário de uma pessoa:\n");
  scanf("%lf", &salario);

  if (salario <= 8157.41) {
    salarioContribuicao = salario;
  } else {
    salarioContribuicao = 8157.41;
  }

  printf("salario = %f\n", salario);
  printf("salario-contribuição = %f\n", salarioContribuicao);

  if (salarioContribuicao <= 1518) {
    printf("Percentual = 7,5%% - desconto = %f\n", salarioContribuicao * 0.075);
  } else if (salarioContribuicao <= 2793.88) {
    printf("Percentual = 9%% - desconto = %f\n", salarioContribuicao * 0.09);
  } else if (salarioContribuicao <= 4190.83) {
    printf("Percentual = 12%% - desconto = %f\n", salarioContribuicao * 0.12);
  } else {
    printf("Percentual = 14%% - desconto = %f\n", salarioContribuicao * 0.14);
  }

  return 0;
}
