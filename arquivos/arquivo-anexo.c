#include <stdio.h>

int main() {
  int num1 = 10, num2 = 50;
  FILE *arq = fopen("notas.txt", "at");
  if (arq == NULL) {
    printf("Arquivo não pode ser aberto!\n");
    return 1; // código de erro 1
  }

  fprintf(arq, "-Olá Turma!\n");
  fprintf(arq, "-num1 = %d\n-num2 = %d\n", num1, num2);

  printf("Arquivo aberto com sucesso!\n");
  fclose(arq);
  return 0;
}