#include <stdio.h>
#include <string.h>

const int TAM = 100;

void lerStr(char *str, int count);
void myStrCpy(char *str1, char *str2);

int main() {
  char nome[TAM];
  printf("Digite o seu nome: ");

  lerStr(nome, TAM);

  printf("O nome digitado foi \"%s\"\n", nome);

  // nome = "Maria Jose"; // ERRADO!!!!! Precisa usar strcpy
  strcpy(nome, "Maria Jose");

  printf("O nome foi alterado para \"%s\"\n", nome);

  return 0;
}

void lerStr(char *str, int count) {
  fgets(str, count, stdin);
  int tam = strlen(str);
  if (tam > 0 && str[tam - 1] == '\n') {
    str[tam - 1] = '\0';
  }
}

// exemplo de como você poderia implementar o strcpy
void myStrCpy(char *dest, char *orig) {
  int i = 0;
  while (orig[i] != '\0') {
    dest[i] = orig[i];
    i += 1;
  }
  dest[i] = '\0';
}
