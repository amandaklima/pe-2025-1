#include <stdio.h>
#include <string.h>

const int TAM_TEMP = 256;
const int QTD_PESSOAS = 3;
const int TAM_NOME = 20;

void lerStr(char *str, int count);

int main() {
  char strTemp[TAM_TEMP];
  char nomes[QTD_PESSOAS][TAM_NOME];
  int idades[QTD_PESSOAS];

  for (int i = 0; i < QTD_PESSOAS; i += 1) {
    printf("Digite o nome[%d]: ", i);
    lerStr(nomes[i], TAM_NOME);
    printf("Digite a idade[%d]: ", i);
    scanf("%d", &idades[i]);
    lerStr(strTemp, TAM_TEMP);
  }

  printf("\nNOMES DIGITADOS\n");
  for (int i = 0; i < QTD_PESSOAS; i += 1) {
    printf("nomes[%d] = %-20s - idades[%d] = %3d\n", i, nomes[i], i, idades[i]);
  }

  return 0;
}

void lerStr(char *str, int count) {
  fgets(str, count, stdin);
  int tam = strlen(str);
  if (tam > 0 && str[tam - 1] == '\n') {
    str[tam - 1] = '\0';
  }
}