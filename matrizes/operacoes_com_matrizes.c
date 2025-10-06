#include <stdio.h>

#define ORDEM 5

void preencherMatrizDigitacao(int matriz[][ORDEM], int qtdLinhas, int qtdColunas);
void imprimirMatriz(int m[][ORDEM], int qtdLinhas, int qtdColunas);
void transporMatriz(int m[][ORDEM], int ordem);
void zerarAbaixoDigPrincipal(int m[][ORDEM], int ordem);
void zerarAcimaDigSecundaria(int m[][ORDEM], int ordem);
void transporMatrizSemIF(int m[][ORDEM], int ordem);

int main() {
  int matriz[ORDEM][ORDEM];
  printf("Preenchimento da matriz\n");
  preencherMatrizDigitacao(matriz, ORDEM, ORDEM);
  printf("\nImpressão da Matriz\n");
  imprimirMatriz(matriz, ORDEM, ORDEM);
  transporMatrizSemIF(matriz, ORDEM);
  printf("\nImpressão da Matriz Transposta\n");
  imprimirMatriz(matriz, ORDEM, ORDEM);
  zerarAbaixoDigPrincipal(matriz, ORDEM);
  printf("\nImpressão da Matriz Após Zerar Abaixo da Diagonal Principal\n");
  imprimirMatriz(matriz, ORDEM, ORDEM);
  zerarAcimaDigSecundaria(matriz, ORDEM);
  printf("\nImpressão da Matriz Após Zerar Acima da Diagonal Secundária\n");
  imprimirMatriz(matriz, ORDEM, ORDEM);
  return 0;
}

void preencherMatrizDigitacao(int m[][ORDEM], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("Digite valor da posição (%d, %d): \n", l + 1, c + 1);
      scanf("%d", &m[l][c]);
    }
  }
}

void imprimirMatriz(int m[][ORDEM], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("%2d ", m[l][c]);
    }
    printf("\n");
  }
}

void transporMatriz(int m[][ORDEM], int ordem) {
  for (int l = 0; l < ordem; l += 1) {
    for (int c = 0; c < ordem; c += 1) {
      if (c > l) {
        int aux = m[c][l];
        m[c][l] = m[l][c];
        m[l][c] = aux;
      }
    }
  }
}

void transporMatrizSemIF(int m[][ORDEM], int ordem) {
  for (int l = 0; l < ordem - 1; l += 1) {
    for (int c = l + 1; c < ordem; c += 1) {
      int aux = m[c][l];
      m[c][l] = m[l][c];
      m[l][c] = aux;
    }
  }
}

void zerarAbaixoDigPrincipal(int m[][ORDEM], int ordem) {
  for (int l = 0; l < ordem; l += 1) {
    for (int c = 0; c < ordem; c += 1) {
      if (l > c) {
        m[l][c] = 0;
      }
    }
  }
}

void zerarAcimaDigSecundaria(int m[][ORDEM], int ordem) {
  for (int l = 0; l < ordem; l += 1) {
    for (int c = 0; c < ordem; c += 1) {
      if (l + c < ordem - 1) {
        m[l][c] = 0;
      }
    }
  }
}