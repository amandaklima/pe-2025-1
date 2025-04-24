#include <stdio.h>
#include <stdlib.h>

const int ORDEM = 100;
void multiplicarMatrizes(
  int m1[][ORDEM], int qtdLinhas1, int qtdColunas1,
  int m2[][ORDEM], int qtdLinhas2, int qtdColunas2,
  int matMult[][ORDEM]
);
void preencherMatriz(int m[][ORDEM], int qtdLinhas, int qtdColunas);
void imprimirMatriz(int m[][ORDEM], int qtdLinhas, int qtdColunas);

int main() {
  int matriz1[ORDEM][ORDEM], matriz2[ORDEM][ORDEM], matriz3[ORDEM][ORDEM];
  int qtdLinhas1 = 5, qtdColunas1 = 7, qtdLinhas2 = 7, qtdColunas2 = 8;
  srand(7);
  preencherMatriz(matriz1, qtdLinhas1, qtdColunas1);
  preencherMatriz(matriz2, qtdLinhas2, qtdColunas2);
  printf("MATRIZ 1\n");
  imprimirMatriz(matriz1, qtdLinhas1, qtdColunas1);
  printf("MATRIZ 2\n");
  imprimirMatriz(matriz2, qtdLinhas2, qtdColunas2);
  multiplicarMatrizes(
      matriz1, qtdLinhas1, qtdColunas1,
      matriz2, qtdLinhas2, qtdColunas2,
      matriz3
  );
  printf("MATRIZ 3\n");
  imprimirMatriz(matriz3, qtdLinhas1, qtdColunas2);
  return 0;
}

void preencherMatriz(int m[][ORDEM], int qtdLinhas, int qtdColunas) {
  for (int i = 0; i < qtdLinhas; i += 1) {
    for (int j = 0; j < qtdColunas; j += 1) {
      m[i][j] = rand() % 10 + 1;
    }
  }
}

void imprimirMatriz(int m[][ORDEM], int qtdLinhas, int qtdColunas) {
  for (int i = 0; i < qtdLinhas; i += 1) {
    for (int j = 0; j < qtdColunas; j += 1) {
      printf("%4d ", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void multiplicarMatrizes(
  int m1[][ORDEM], int qtdLinhas1, int qtdColunas1,
  int m2[][ORDEM], int qtdLinhas2, int qtdColunas2,
  int matMult[][ORDEM]
) {
  if (qtdColunas1 != qtdLinhas2) {
    printf("Não é possível multiplicar essas duas matrizes");
  }

  for (int i = 0; i < qtdLinhas1; i += 1) {
    for (int j = 0; j < qtdColunas2; j += 1) {
      matMult[i][j] = 0;
      for (int k = 0; k < qtdColunas1; k += 1) {
        matMult[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}