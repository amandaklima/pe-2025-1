#include <stdio.h>
#include <string.h>

#define QTD_FRASES 5
#define TAM_FRASE 100

void lerStr(char str[], int tam);
void inserirFrase(char vs[][TAM_FRASE], int *n);
void imprimirFrases(char vs[][TAM_FRASE], int n);

int main() {
  char frases[QTD_FRASES][TAM_FRASE];
  int opcao, tam = 0;
  do {
    printf("\n\nMENU\n");
    printf("1 - Inserir uma frase no vetor\n");
    printf("2 - Imprimir frases\n");
    printf("Digite a sua opção:\n");
    scanf("%d", &opcao);
    switch(opcao) {
      case 1:
        inserirFrase(frases, &tam);
        break;
      case 2:
        printf("Impressão das frases\n");
        imprimirFrases(frases, tam);
        break;
      default:
        if (opcao != 0) {
          printf("Digitou uma opção inválida!\n");
        }
        break;
      }
  } while (opcao != 0);
}

void inserirFrase(char vs[][TAM_FRASE], int *n) {
  if (*n >= QTD_FRASES) {
    printf("Vetor cheio!\n");
    return;
  }

  printf("Digite uma frase:\n");
  lerStr(vs[*n], TAM_FRASE); // Esse comando vai ler APENAS o ENTER da digitação anterior
  lerStr(vs[*n], TAM_FRASE);
  *n += 1;
}

void imprimirFrases(char vs[][TAM_FRASE], int n) {
  for (int i = 0; i < n; i += 1) {
    printf("frase[%d] = %s\n", i + 1, vs[i]);
  }
}

void lerStr(char str[], int tam) {
  fgets(str, tam, stdin);
  int tamDigitado = strlen(str);
  if (str[tamDigitado - 1] == '\n') {
    str[tamDigitado - 1] = '\0';
  }
}