#include <stdio.h>

int main() {
  int num;
  printf("Digite um numero inteiro: ");
  scanf("%d", &num);

  if (num > 0) {
    printf("Voce digitou um numero positivo!\n");
  } else if (num == 0) {
    printf("Voce digitou um numero neutro\n");
  } else {
    printf("Voce digitou um numero negativo\n");
  }
  
  return 0;
}