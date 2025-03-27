#include <stdio.h>

const int QTD_LINHAS = 100;
const int QTD_COLUNAS = 200;

void preencherMatrizDigitacao(int m[][QTD_COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; i += 1) {
    for (int j = 0; j < colunas; j += 1) {
      printf("Digite o valor de m[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &m[i][j]);
    }
  }
}

void imprimirMatriz(int m[][QTD_COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; i += 1) {
    for (int j = 0; j < colunas; j += 1) {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }
}

int digitarIntervalo(int min, int max) {
  int num;
  do {
    printf("Digite um valor entre %d e %d: ", min, max);
    scanf("%d", &num);
  } while (num < min || num > max);
  return num;
}

int main() {
  int matriz[QTD_LINHAS][QTD_COLUNAS];
  int qtdLinhas, qtdColunas;
  printf("Digite o numero de linhas\n");
  qtdLinhas = digitarIntervalo(1, QTD_LINHAS);
  printf("\nDigite o numero de colunas\n");
  qtdColunas = digitarIntervalo(1, QTD_COLUNAS);
  printf("\nPreencha a matriz\n");
  preencherMatrizDigitacao(matriz, qtdLinhas, qtdColunas);
  printf("\n\nImpressao\n");
  imprimirMatriz(matriz, qtdLinhas, qtdColunas);
}