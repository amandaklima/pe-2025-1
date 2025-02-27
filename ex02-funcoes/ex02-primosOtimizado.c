#include <stdio.h>
#include <math.h>

const int MAX_NUM = 10000000;

int ehPrimo(int num) {
  if (num == 1) {
    return 0;
  }
  for (int divisor = 2; divisor < num / 2; divisor += 1) {
    if (num % divisor == 0) {
      return 0;
    }
  }
  return 1;
}

int ehPrimoOtimizada(int num) {
    int k = 1, a = 0, b = 0;
    long sr;
    switch(num)
        {
        case 1: return 0;
        case 2: return 1;
        case 3: return 1;
        case 4: return 0;
        case 5: return 1;
        case 6: return 0;
        case 7: return 1;
    }
    if (num % 2 == 0) return 0;
    if (num % 3 == 0) return 0;
    sr = (int) sqrt(num);
    while (b < sr) {
        a = (6 * k) - 1;
        b = (6 * k) + 1;
        if (num % a == 0)
            return 0;
        if (num % b == 0)
            return 0;
        k += 1;
    }
    return 1;
}

int main() {
  int qtdPrimos = 0;
  printf("Listagem dos numeros primos entre 1 e %d\n", MAX_NUM);
  for (int num = 9500000; num <= MAX_NUM; num += 1) {
    if (ehPrimoOtimizada(num)) {
      qtdPrimos += 1;
      printf("%d ", num);
    }
  }
  printf("\n\nExistem %d primos entre 1 e %d\n\n", qtdPrimos, MAX_NUM);
  return 0;
}
