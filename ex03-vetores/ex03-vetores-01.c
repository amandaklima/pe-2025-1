#include <stdio.h>

const int QTD_ALUNOS = 3;

int main() {
  double notas[QTD_ALUNOS];
  printf("Digitacao de todas as notas da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Digite a nota %d: ", i + 1);
    scanf("%lf", &notas[i]);
  }

  printf("\nImpressao de todas as notas da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Nota %d: %.2f\n", i + 1, notas[i]);
  }
  return 0;
}