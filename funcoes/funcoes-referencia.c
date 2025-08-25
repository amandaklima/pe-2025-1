#include <stdio.h>

double dobro(double x);
int ehPrimo(int x);
int ehPrimoMelhorada(int x);

int main() {
  double num, result;
  int num2, primo;
  printf("Digite um número real: ");
  scanf("%lf", &num);
  result = dobro(num);
  printf("O dobro de %f é %f\n", num, result);

  printf("Digite um número inteiro: ");
  scanf("%d", &num2);
  primo = ehPrimo(num2);
  if (primo) {
    printf("O número %d é primo!\n", num2);
  } else {
    printf("O número %d não é primo!\n", num2);
  }

  for (int i = 1; i < 1000000; i += 1) {
    if (ehPrimoMelhorada(i)) {
      printf("%d ", i);
    }
  }
    return 0;
}

double dobro(double x) {
  return 2 * x;
}

int ehPrimo(int x) {
  int qtdDivisores = 0;
  for (int divisor = 1; divisor <= x; divisor +=1) {
    if (x % divisor == 0) {
      qtdDivisores += 1;
    }
  }

  return qtdDivisores == 2;
}

int ehPrimoMelhorada(int x) {
  if (x < 2) {
    return 0;
  } else if (x == 2) {
    return 1;
  }

  for (int divisor = 2; divisor * divisor <= x; divisor +=1) {
    if (x % divisor == 0) {
      return 0;
    }
  }

  return 1;
}
