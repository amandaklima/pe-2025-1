#include <stdio.h>

int main() {
  int num1 = 8, num2 = 1000, num3 = -234;
  int status;
  FILE *arq = fopen("numeros.bin", "wb");
  if (arq == NULL) {
    printf("Nao conseguiu abrir o arquivo!\n");
    return 1;
  }

  status = fwrite(&num1, sizeof(int), 1, arq);
  if (status == 1) {
    printf("num1 gravado com sucesso!\n");
  } else {
    printf("erro ao salvar num1\n");
  }

  status = fwrite(&num2, sizeof(int), 1, arq);
  if (status == 1) {
    printf("num2 gravado com sucesso!\n");
  } else {
    printf("erro ao salvar num2\n");
  }

  status = fwrite(&num3, sizeof(int), 1, arq);
  if (status == 1) {
    printf("num3 gravado com sucesso!\n");
  } else {
    printf("erro ao salvar num3\n");
  }

  if (fclose(arq) == 0) {
    printf("Arquivo fechado com sucesso!");
  } else {
    printf("Erro ao fechar o arquivo!");
  }

  return 0;
}