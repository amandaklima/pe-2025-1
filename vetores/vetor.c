#include <stdio.h>

#define TAM 5

int main() {
  int numeros[TAM];
  int soma = 0;
  double media;
  for (int i = 0; i < TAM; i += 1) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &numeros[i]);
    soma += numeros[i];
  }
  media = (double) soma / (double) TAM;
  printf("A média dos números digitados é %.2f\n", media);
  for (int i = 0; i < TAM; i += 1) {
    if (numeros[i] > media) {
      printf("numeros[%d] = %d\n", i + 1, numeros[i]);
    }
  }
  return 0;
}