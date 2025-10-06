#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 6

void preencherMatrizDigitacao(int matriz[][QTD_COLUNAS], int qtdLinhas, int qtdColunas);
void imprimirMatriz(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas);
void imprimirMatrizTransposta(int m[][QTD_LINHAS], int qtdLinhas, int qtdColunas);
void criarMatrizTransposta(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas, int mt[][QTD_LINHAS]);

int main()
{
  int matriz[QTD_LINHAS][QTD_COLUNAS];
  int transposta[QTD_COLUNAS][QTD_LINHAS];
  printf("Preenchimento da matriz\n");
  preencherMatrizDigitacao(matriz, QTD_LINHAS, QTD_COLUNAS);
  printf("\nImpressão da Matriz\n");
  imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
  criarMatrizTransposta(matriz, QTD_LINHAS, QTD_COLUNAS, transposta);
  printf("\nImpressão da Matriz Transposta\n");
  imprimirMatrizTransposta(transposta, QTD_COLUNAS, QTD_LINHAS);
  return 0;
}

void preencherMatrizDigitacao(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("Digite valor da posição (%d, %d): \n", l + 1, c + 1);
      scanf("%d", &m[l][c]);
    }
  }
}

void imprimirMatriz(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("%2d ", m[l][c]);
    }
    printf("\n");
  }
}

void imprimirMatrizTransposta(int m[][QTD_LINHAS], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("%2d ", m[l][c]);
    }
    printf("\n");
  }
}

void criarMatrizTransposta(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas, int mt[][QTD_LINHAS]) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      mt[c][l] = m[l][c];
    }
  }
}