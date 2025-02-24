#include <stdio.h>

#define MAX_REPET 5

int main() {
  int num1, num2, qtdRepet = 1;
  printf("Digite um numero inteiro: ");
  scanf("%d", &num1);

  printf("Digite um numero inteiro maior que %d: ", num1);
  scanf("%d", &num2);

  while (num2 <= num1) {
    printf("Valor digitado e invalido!\n");
    printf("Digite um numero inteiro maior que %d\n", num1);
    scanf("%d", &num2);
  }

  // while (num2 <= num1 && qtdRepet <= MAX_REPET) {
  //   qtdRepet = qtdRepet + 1;
  //   printf("Valor digitado e invalido!\n");
  //   printf("Digite um numero inteiro maior que %d\n", num1);
  //   scanf("%d", &num2);
  // }

  if (qtdRepet <= MAX_REPET) {
    printf("Existem %d valores no intervalo de %d a %d\n", 
      num2 - num1 + 1, num1, num2);
      return 0;
  } else {
    printf("Estorou a quantidade de repeticoes!\n");
    return 1;
  }
}