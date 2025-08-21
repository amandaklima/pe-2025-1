#include <stdio.h>

void trocar(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main() {
  int numero1 = 10, numero2 = 20;
  printf("numero1 = %d - numero2 = %d\n", numero1, numero2);
  trocar(&numero1, &numero2);
  printf("numero1 = %d - numero2 = %d\n", numero1, numero2);
  return 0;
}
