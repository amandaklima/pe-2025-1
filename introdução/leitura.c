#include <stdio.h>

int main() {
  int idade;
  double peso, altura;

  printf("Digite a sua idade:\n");
  scanf("%d", &idade);

  printf("Digite a altura:\n");
  scanf("%lf", &altura);

  printf("Digite o seu peso:\n");
  scanf("%lf", &peso);

  printf("idade = %d\n", idade);
  printf("peso = %f - altura = %f\n", peso, altura);
  return 0;
}
