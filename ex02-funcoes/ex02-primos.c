#include <stdio.h>

const int MAX_NUM = 10000000;

int ehPrimo(int num) {
  int qtdDivisores = 0;
  for (int divisor = 1; divisor <= num; divisor += 1) {
    if (num % divisor == 0) {
      qtdDivisores += 1;
    }
  }
  return qtdDivisores == 2;
}

int main() {
  int qtdPrimos = 0;
  printf("Listagem dos numeros primos entre 1 e %d\n", MAX_NUM);
  for (int num = 9500000; num <= MAX_NUM; num += 1) {
    if (ehPrimo(num)) {
      qtdPrimos += 1;
      printf("%d ", num);
    }
  }
  printf("\n\nExistem %d primos entre 1 e %d\n\n", qtdPrimos, MAX_NUM);
  return 0;
}

// Programa que fica solicitando números inteiros para
// o usuário digitar e imprime se cada um dele é ou não
// primo. Quando o usuário digitar um número <= 0,
// encerra o programa
// int main() {
//   int numero;
//   printf("Digite um numero inteiro positivo: ");
//   scanf("%d", &numero);
//   do {
//     if (ehPrimo(numero)) {
//       printf("%d eh primo!\n", numero);
//     } else {
//       printf("%d nao eh primo!\n", numero);
//     }
//     printf("Digite um numero inteiro (<= 0 para encerrar): ");
//     scanf("%d", &numero);
//   } while (numero > 0);
//   printf("Programa finalizado!\n");
//   return 0;
// }
