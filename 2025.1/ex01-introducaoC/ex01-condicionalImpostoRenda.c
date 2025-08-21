/*
Faça um programa em C que solicite que o usuário digite
 o seu salário e você deve imprimir o percentual de 
 desconto do Imposto de Renda.
*/

#include <stdio.h>

int main() {
  double salario;
  printf("CALCULO ALIQUOTA DO IMPOSTO DE RENDA\n\n");
  printf("Digite o seu salario: ");
  scanf("%lf", &salario);
  if (salario <= 2259.20) {
    printf("A aliquota do seu imposto de renda e 0%%\n");
  } else if (salario <= 2826.65) {
    printf("A aliquota do seu imposto de renda e 7,5%%\n");
  } else if (salario <= 3751.05) {
    printf("A aliquota do seu imposto de renda e 15%%\n");
  } else if (salario <= 4664.68) {
    printf("A aliquota do seu imposto de renda e 22,5%%\n");
  } else {
    printf("A aliquota do seu imposto de renda e 27,5%%\n");
  }
  return 0;
}