#include <stdio.h>
#include <math.h>

int main() {
  int num;
  printf("Digite um número natural (>= 0): ");
  scanf("%d", &num);
  while (num < 0) {
    printf("Número inválido!\n");
    printf("Digite um número natural (>= 0): ");
    scanf("%d", &num);
  }

  printf("A raiz quadrada de %d é %f\n", num, sqrt(num));

  return 0;
}