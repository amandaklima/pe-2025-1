#include <stdio.h>

const int M = 30;
const int N = 20;

void criarVetorMaiorColuna(int m[][N], int v[], int qtdLinhas, int qtdColunas) {
  int maior;
  for (int j = 0; j < qtdColunas; j += 1) {
    maior = m[0][j];
    for (int i = 0; i < qtdLinhas; i += 1) {
      if (m[i][j] > maior) {
        maior = m[i][j];
      }
    }
    v[j] = maior;
  }
}
