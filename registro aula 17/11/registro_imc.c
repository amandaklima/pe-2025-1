#include <stdio.h>
#include <string.h>

#define TAM 10
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
void preencherVetorPessoas(struct Pessoa v[], int tam);
void imprimirVetorPessoas(struct Pessoa v[], int tam);
void insertionSortPorNome(struct Pessoa v[], int tam);
void insertionSortPorAltura(struct Pessoa v[], int tam);
void insertionSortPorPesoDecrescente(struct Pessoa v[], int tam);
void insertionSortPorIMC(struct Pessoa v[], int tam);
void selectionSortPorNome(struct Pessoa v[], int tam);
void bubbleSortPorPeso(struct Pessoa v[], int tam);

int main()
{
  struct Pessoa pessoas[TAM];
  preencherVetorPessoas(pessoas, TAM);
  imprimirVetorPessoas(pessoas, TAM);
  printf("\nOrdenação por Nome\n");
  selectionSortPorNome(pessoas, TAM);
  imprimirVetorPessoas(pessoas, TAM);
  printf("\nOrdenação por Altura\n");
  insertionSortPorAltura(pessoas, TAM);
  imprimirVetorPessoas(pessoas, TAM);
  printf("\nOrdenação por Peso (descrescente)\n");
  insertionSortPorPesoDecrescente(pessoas, TAM);
  imprimirVetorPessoas(pessoas, TAM);
  printf("\nOrdenação por IMC\n");
  insertionSortPorIMC(pessoas, TAM);
  imprimirVetorPessoas(pessoas, TAM);
  printf("\nOrdenação por Peso (crescente)\n");
  bubbleSortPorPesoENome(pessoas, TAM);
  imprimirVetorPessoas(pessoas, TAM);
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
  char temp[TAM_NOME];
  printf("Digite o seu nome:\n");
  lerStr(p->nome, TAM_NOME);
  printf("Digite o seu peso:\n");
  scanf("%lf", &p->peso);
  printf("Digite a sua altura:\n");
  scanf("%lf", &p->altura);
  lerStr(temp, TAM_NOME);
}

double calcularIMC(struct Pessoa p) {
  return p.peso / (p.altura * p.altura);
}

void preencherVetorPessoas(struct Pessoa v[], int tam) {
  for (int i = 0; i < tam; i += 1) {
    printf("====== Preenchimento das Informações da Pessoa %d ======\n", i + 1);
    preencherPessoa(&v[i]);
  }
}

void imprimirVetorPessoas(struct Pessoa v[], int tam) {
  printf("\n====== Listagem das Informações de Todas as Pessoa ======\n");
  for (int i = 0; i < tam; i += 1) {
    printf("[%2d] ", i + 1);
    imprimirPesssoa(v[i]);
    double imc = calcularIMC(v[i]);
    printf(" tem IMC = %.2f\n", imc);
  }
}

void insertionSortPorNome(struct Pessoa v[], int tam) {
  for (int i = 1; i <= tam - 1; i += 1) {
    struct Pessoa chave = v[i];
    int j = i;
    // while (j > 0 && chave < v[j - 1]) {
    while (j > 0 && strcmp(chave.nome, v[j - 1].nome) < 0) {
      v[j] = v[j - 1];
      j = j - 1;
    }
    v[j] = chave;
  }
}

void insertionSortPorAltura(struct Pessoa v[], int tam) {
  for (int i = 1; i <= tam - 1; i += 1) {
    struct Pessoa chave = v[i];
    int j = i;
    while (j > 0 && chave.altura < v[j - 1].altura) {
      v[j] = v[j - 1];
      j = j - 1;
    }
    v[j] = chave;
  }
}

void insertionSortPorPesoDecrescente(struct Pessoa v[], int tam) {
  for (int i = 1; i <= tam - 1; i += 1) {
    struct Pessoa chave = v[i];
    int j = i;
    while (j > 0 && chave.peso > v[j - 1].peso) {
      v[j] = v[j - 1];
      j = j - 1;
    }
    v[j] = chave;
  }
}

void insertionSortPorIMC(struct Pessoa v[], int tam) {
  for (int i = 1; i <= tam - 1; i += 1) {
    struct Pessoa chave = v[i];
    int j = i;
    while (j > 0 && calcularIMC(chave) < calcularIMC(v[j - 1])) {
      v[j] = v[j - 1];
      j = j - 1;
    }
    v[j] = chave;
  }
}

void selectionSortPorNome(struct Pessoa v[], int tam) {
  struct Pessoa aux;
  for (int i = 0; i < tam - 1; i += 1) {
    int posMenor = i;
    for (int j = i + 1; j < tam; j += 1) {
      if (strcmp(v[j].nome, v[posMenor].nome) < 0) {
        posMenor = j;
      }
    }
    aux = v[i];
    v[i] = v[posMenor];
    v[posMenor] = aux;
  }
}

void bubbleSortPorPesoENome(struct Pessoa v[], int tam) {
  int trocou = 1, fim = tam - 1, pos;
  struct Pessoa aux;
  while (trocou) {
    trocou = 0;

   for (int i = 0; i < fim; i+= 1) {
    if (v[i].peso > v[i + 1].peso || (v[i].peso == v[i + 1].peso && strcmp(v[i].nome, v[i + 1].nome) > 0)) {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        trocou = 1;
        pos = i; 
    }
  }
  fim = pos;
  }
}