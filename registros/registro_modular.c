#include <stdio.h>
#include <string.h>

#define TAM_NOME 256

struct Pessoa {
  char nome[TAM_NOME];
  double peso;
  double altura;
};

void lerStr(char str[], int tam);
void imprimirPesssoa(struct Pessoa p);
void preencherPessoa(struct Pessoa *p);
double calcularIMC(struct Pessoa p);

int main() {
  struct Pessoa p;
  double imc;
  preencherPessoa(&p);
  imc = calcularIMC(p);
  imprimirPesssoa(p);
  printf(" tem IMC = %.2f\n", imc);
  return 0;
}

void lerStr(char str[], int tam) {
  fgets(str, tam, stdin);
  int tamDigitado = strlen(str);
  if (str[tamDigitado - 1] == '\n') {
    str[tamDigitado - 1] = '\0';
  }
}

void imprimirPesssoa(struct Pessoa p) {
  printf("(%s, %.2f kg, %.2f m)", p.nome, p.peso, p.altura);
}

void preencherPessoa(struct Pessoa *p) {
  printf("Digite o seu nome: ");
  lerStr((*p).nome, TAM_NOME);
  printf("Digite o seu peso: ");
  scanf("%lf", &(*p).peso);
  printf("Digite a sua altura: ");
  scanf("%lf", &(*p).altura);
}

double calcularIMC(struct Pessoa p) {
  return p.peso / (p.altura * p.altura);
}