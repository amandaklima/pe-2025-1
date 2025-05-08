#include <stdio.h>
#include <string.h>

const int TAM = 100;

void lerStr(char *str, int count);
int palindroma(char *str);
void removerEspacos(char *str);

int main() {
  char frase[TAM];
  printf("Digite uma frase: ");

  lerStr(frase, TAM);

  printf("A frase digitada foi \"%s\" ", frase);

  removerEspacos(frase);

  if (palindroma(frase)) {
    printf(" e ela eh palindroma\n");
  } else {
    printf(" e ela nao eh palindroma\n");
  }

  printf("\nA frase modificada foi \"%s\" ", frase);

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

void imprimirCodigoAscii(char *str) {
  int tam = strlen(str);
  printf("CHAR\tASCII\n");
  for (int i = 0; i < tam; i += 1)
  {
    printf("%c\t%d\n", str[i], str[i]);
  }
}

void substituir(char *str, char antigo, char novo) {
  int tam = strlen(str);
  for (int i = 0; i < tam; i += 1) {
    if (str[i] == antigo) {
      str[i] = novo;
    }
  }
}

int palindroma(char *str) {
  int tam = strlen(str);
  int metadeTam = tam / 2;
  for (int i = 0; i < metadeTam; i += 1) {
    if (str[i] != str[tam - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

void removerEspacos(char *str) {
  int tam = strlen(str);
  int j = 0;
  for (int i = 0; i < tam; ++i) {
    if (str[i] != ' ') {
      str[j] = str[i];
      j += 1;
    }
  }
  str[j] = '\0';
}