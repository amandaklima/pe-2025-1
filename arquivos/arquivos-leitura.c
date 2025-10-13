#include <stdio.h>
#include <string.h>

#define TAM 256
void lerStrArq(char str[], int tam, FILE *arq);

int main() {
  char frase[TAM];
  FILE *arq = fopen("notas.txt", "rt");
  if (arq == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
  }
  printf("Arquivo aberto com sucesso!\n");

  lerStrArq(frase, TAM, arq);
  while (!feof(arq)) {
    printf("-->%s<--\n", frase);
    lerStrArq(frase, TAM, arq);
  }

  fclose(arq);
  return 0;
}

void lerStrArq(char str[], int tam, FILE *arq) {
  fgets(str, tam, arq);
  int tamDigitado = strlen(str);
  if (str[tamDigitado - 1] == '\n') {
    str[tamDigitado - 1] = '\0';
  }
}