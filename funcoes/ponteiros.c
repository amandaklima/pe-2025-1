#include <stdio.h>

void troca(int *a, int *b);

int main() {
  int num1, num2;
  printf("Digite um número inteiro: ");
  scanf("%d", &num1);
  printf("Digite outro número inteiro: ");
  scanf("%d", &num2);
  printf("\n\n==========Antes da troca==========\n");
  printf("num1 = %d\n", num1);
  printf("num2 = %d\n", num2);
  troca(&num1, &num2);
  printf("\n\n==========Após a troca==========\n");
  printf("num1 = %d\n", num1);
  printf("num2 = %d\n", num2);
  return 0;
}

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}