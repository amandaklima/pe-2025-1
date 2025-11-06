// Criar o registro Aluno que tem os campos nota1 e nota2.
// Preencher e imprimir as informações de aluno, incluíndo a sua média (que deve ser calculada
// usando peso 2 para a nota1 e peso 3 para a nota2)

#include <stdio.h>

struct Aluno {
  double nota1;
  double nota2;
};

void imprimirAluno(struct Aluno al);
void preencherAluno(struct Aluno *al);
double calcularMedia(struct Aluno al);

int main() {
  struct Aluno aluno;
  preencherAluno(&aluno);
  imprimirAluno(aluno);
  double media = calcularMedia(aluno);
  printf("A média é %.2f\n", media);
  return 0;
}

void imprimirAluno(struct Aluno al) {
  printf("(%.2f, %.2f)\n", al.nota1, al.nota2);
}

void preencherAluno(struct Aluno *al) {
  printf("Digite a primeira nota: ");
  scanf("%lf", &al->nota1);
  printf("Digite a segunda nota: ");
  scanf("%lf", &al->nota2);
}

double calcularMedia(struct Aluno al) {
  return (al.nota1 * 2 + al.nota2 * 3) / 5;
}