#include <stdio.h>

int main() {
  int num1, num2;
  printf("Digite um numero inteiro: ");
  scanf("%d", &num1);

  do {
    printf("Digite um numero inteiro maior que %d\n", num1);
    scanf("%d", &num2);
    if (num2 <= num1) {
      printf("Valor digitado e invalido!\n");
    }
  } while (num2 <= num1);

  printf("Existem %d valores no intervalo de %d a %d\n", 
    num2 - num1 + 1, num1, num2);
  return 0;
}