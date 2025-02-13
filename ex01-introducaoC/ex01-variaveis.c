#include <stdio.h>

int main() {
  int n1;
  double n2;
  char letra1 = 'a', letra2 = 'b';

  printf("Digite um valor inteiro: ");
  scanf("%d", &n1);

  printf("Digite um valor real: ");
  scanf("%lf", &n2);

  printf("n1 = %d e n2 = %.2f\n", n1, n2);
  printf("letra1 = %c e letra2 = %c\n", letra1, letra2);
  return 0;
}
