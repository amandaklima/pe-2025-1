#include <stdio.h>

int main() {
  int num;
  FILE *arq = fopen("numerosVetor.bin", "rb");
  if (arq == NULL) {
    printf("Nao conseguiu abrir o arquivo!\n");
    return 1;
  }

  fread(&num, sizeof(int), 1, arq);
  while (!feof(arq)) {
    printf("%3d\n", num);
    fread(&num, sizeof(int), 1, arq);
  }

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