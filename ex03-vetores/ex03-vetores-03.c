#include <stdio.h>

const int QTD_ALUNOS = 5;

void preencherNotasTurma(double notas[QTD_ALUNOS]) {
  printf("Digitacao de todas as notas da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Digite a nota %d: ", i + 1);
    scanf("%lf", &notas[i]);
  }
}

double calcularMediaTurma(double notas[QTD_ALUNOS]) {
  double somatorio = 0;
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    somatorio += notas[i];
  }
  return somatorio / QTD_ALUNOS;
}

void imprimirNotasTurma(double notas[QTD_ALUNOS]) {
  printf("\nImpressao de todas as notas da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Nota %d: %.2f\n", i + 1, notas[i]);
  }
}

void imprimirNotasAcimaMedia(
  double notas[QTD_ALUNOS], double media
) {
  printf("\nImpressao de todas as notas acima da media da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    if (notas[i] > media) {
      printf("Nota %d: %.2f\n", i + 1, notas[i]);
    }
  }
}

int main() {
  double notas[QTD_ALUNOS];
  double media;
  preencherNotasTurma(notas);
  media = calcularMediaTurma(notas);
  printf("\nMedia da turma: %.2f\n", media);
  imprimirNotasTurma(notas);
  imprimirNotasAcimaMedia(notas, media);
  return 0;
}
