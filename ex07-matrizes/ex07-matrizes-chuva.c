#include <stdio.h>
#include <stdlib.h>
#include <float.h> // para utilizar DBL_MAX

const int QTD_ANOS = 5;
const int QTD_MESES = 12;

void preencherMatriz(double chuvas[QTD_ANOS][QTD_MESES]);
void imprimirMatriz(double chuvas[QTD_ANOS][QTD_MESES]);
void imprimirMesMaisSeco(double chuvas[QTD_ANOS][QTD_MESES]);
void imprimirMediaPorMes(double chuvas[QTD_ANOS][QTD_MESES]);

int main() {
  double chuvas[QTD_ANOS][QTD_MESES];
  srand(7);
  preencherMatriz(chuvas);
  imprimirMatriz(chuvas);
  imprimirMesMaisSeco(chuvas);
  imprimirMediaPorMes(chuvas);
}

void preencherMatriz(double chuvas[QTD_ANOS][QTD_MESES]) {
  for (int i = 0; i < QTD_ANOS; i += 1) {
    for (int j = 0; j < QTD_MESES; j += 1) {
      chuvas[i][j] = (rand() % 1000) / 10.0;
    }
  }
}

void imprimirMatriz(double chuvas[QTD_ANOS][QTD_MESES]) {
  printf("      ");
  for (int i = 0; i < QTD_MESES; i += 1) {
    printf(" %2d  ", i + 1);
  }
  printf("\n");
  for (int i = 0; i < QTD_ANOS; i += 1) {
    printf("%d: ", 2020 + i);
    for (int j = 0; j < QTD_MESES; j += 1) {
      printf("%4.1f ", chuvas[i][j]);
    }
    printf("\n");
  }
}

void imprimirMesMaisSeco(double chuvas[QTD_ANOS][QTD_MESES]) {
  int mes = 0, ano = 0;
  for (int i = 0; i < QTD_ANOS; i += 1) {
    for (int j = 0; j < QTD_MESES; j += 1) {
      if (chuvas[i][j] < chuvas[ano][mes]) {
        ano = i;
        mes = j;
      }
    }
  }
  printf("O mes/ano mais seco foi %d/%d\n", mes + 1, 2020 + ano);
}

void imprimirMediaPorMes(double chuvas[QTD_ANOS][QTD_MESES]) {
  double soma, media, mediaMesMaisSeco = DBL_MAX;
  int indiceMesMaisSeco = 0;
  for (int j = 0; j < QTD_MESES; j += 1) {
    soma = 0.0;
    for (int i = 0; i < QTD_ANOS; i += 1) {
      soma += chuvas[i][j];
    }
    media = soma / QTD_ANOS;
    printf("A media de chuvas no mes %2d = %4.1f\n", j + 1, media);
    if (media < mediaMesMaisSeco) {
      mediaMesMaisSeco = media;
      indiceMesMaisSeco = j;
    }
  }
  printf("Em media, o mes mais seco eh %d com %.1f\n", indiceMesMaisSeco + 1, mediaMesMaisSeco);
}