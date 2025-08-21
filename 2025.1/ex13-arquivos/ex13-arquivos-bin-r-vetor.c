#include <stdio.h>

#define TAM 10
void imprimirVetor(int v[], int tam);

int main() {
  int numeros[TAM];
  int status;
  FILE *arq = fopen("numerosVetor.bin", "rb");
  if (arq == NULL) {
    printf("Nao conseguiu abrir o arquivo!\n");
    return 1;
  }

  status = fread(numeros, sizeof(int), TAM, arq);
  if (status != TAM) {
    printf("erro ao ler vetor numeros\n");
  }

  imprimirVetor(numeros, TAM);

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

void imprimirVetor(int v[], int tam) {
  for (int i = 0; i < tam; i += 1) {
    printf("numeros[%d]: %3d\n", i + 1, v[i]);
  }
}
