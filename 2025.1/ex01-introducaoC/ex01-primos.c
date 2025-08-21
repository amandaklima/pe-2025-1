#include <stdio.h>

int main() {
  int num;
  printf("Digite um numero inteiro: ");
  scanf("%d", &num);

  // ------------------ Testando se 'num' é primo -----------------
  int divisor, qtdDivisores = 0;
  for (divisor = 1; divisor <= num; divisor += 1) {
    if (num % divisor == 0) {
      qtdDivisores += 1;
    }
  }

  if (qtdDivisores == 2) {
    printf("%d eh um numero primo!\n", num);
  } else {
    printf("%d nao eh um numero primo!\n", num);
  }

  return 0;
}
