#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int QTD = 100;

void preencherVetorAleatorio(int v[QTD]) {
  for (int i = 0; i < QTD; i += 1) {
    v[i] = rand() % 1000 + 1;
  }
}

void imprimirVetor(int v[QTD]) {
  for (int i = 0; i < QTD; i += 1) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int buscar(int v[QTD], int x) {
  for (int i = 0; i < QTD; i += 1) {
    if (v[i] == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  int numeros[QTD];
  int num, pos;
  // srand(time(NULL));
  srand(7);
  preencherVetorAleatorio(numeros);
  imprimirVetor(numeros);
  printf("Digite um valor entre 1 e 1000: ");
  scanf("%d", &num);
  while (num >= 1 && num <= 1000) {
    pos = buscar(numeros, num);
    if (pos != -1) {
      printf("O numero %d esta dentro do vetor na %da posicao!\n", num, pos + 1);
    } else {
      printf("O numero %d nao esta dentro do vetor!\n", num);
    }
    printf("Digite um valor entre 1 e 1000: ");
    scanf("%d", &num);
  }
  return 0;
}