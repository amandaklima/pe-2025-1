#include <stdio.h>
#include <string.h>

const int TAM = 100;

void lerStr(char *str, int count);
void myStrCpy(char *dest, char *orig);
void imprimirCodigoAscii(char *str);
void substituir(char *str, char antigo, char novo);

int main()
{
  char nome[TAM];
  printf("Digite o seu nome: ");

  lerStr(nome, TAM);

  printf("O nome digitado foi \"%s\"\n", nome);

  // nome = "Maria Jose Santos"; // ERRADO!!!!! Precisa usar strcpy
  strcpy(nome, "Maria Jose Santos");
  substituir(nome, 'a', 'e');
  printf("O nome foi alterado para \"%s\"\n", nome);

  imprimirCodigoAscii(nome);

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
