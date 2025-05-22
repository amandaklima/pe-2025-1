#include <stdio.h>

int main() {
  int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
  int status;
  FILE *arq = fopen("numeros.bin", "rb");
  if (arq == NULL) {
    printf("Nao conseguiu abrir o arquivo!\n");
    return 1;
  }

  status = fread(&num1, sizeof(int), 1, arq);
  if (status != 1) {
    printf("erro ao ler num1\n");
  }

  status = fread(&num2, sizeof(int), 1, arq);
  if (status != 1) {
    printf("erro ao ler num2\n");
  }

  status = fread(&num3, sizeof(int), 1, arq);
  if (status != 1) {
    printf("erro ao ler num3\n");
  }

  status = fread(&num4, sizeof(int), 1, arq);
  if (status != 1) {
    printf("erro ao ler num4\n");
  }

  printf("valores lidos do arquivo: %d, %d, %d, %d\n\n",
    num1, num2, num3, num4);

  if (fclose(arq) == 0)
  {
    printf("Arquivo fechado com sucesso!");
  }
  else
  {
    printf("Erro ao fechar o arquivo!");
  }

  return 0;
}