#include <stdio.h>

#define TAM 10

int main() {
  int numeros[TAM] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int status;
  FILE *arq = fopen("numerosVetor.bin", "wb");
  if (arq == NULL) {
    printf("Nao conseguiu abrir o arquivo!\n");
    return 1;
  }

  status = fwrite(numeros, sizeof(int), TAM, arq);
  if (status == TAM) {
    printf("vetor numeros gravado com sucesso!\n");
  } else {
    printf("erro ao salvar o vetor numeros\n");
  }

  if (fclose(arq) == 0) {
    printf("Arquivo fechado com sucesso!\n");
  } else {
    printf("Erro ao fechar o arquivo!\n");
  }

  return 0;
}