#include <stdio.h>
#include <math.h>

int main() {
  int num;
  do {
    printf("Digite um número natural (>= 0): ");
    scanf("%d", &num);
    if (num < 0) {
      printf("Número inválido!\n");
    }
  } while (num < 0);

  printf("A raiz quadrada de %d é %f\n", num, sqrt(num));

  return 0;
}