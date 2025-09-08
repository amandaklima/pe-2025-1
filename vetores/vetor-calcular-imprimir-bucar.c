#include <stdio.h>

#define TAM 7

void preencherVetorDigitacao(int vetor[], int tam);
void preencherVetorImpares(int vetor[], int tam);
double calcularMediaVetor(int vetor[], int tam);
void imprimirValoresAcimaValor(int vetor[], int tam, double valor);
int buscaSequencial(int vetor[], int tam, int x);
void realizarDiversasBuscas(int vetor[], int tam);
int estaOrdenado(int vetor[], int tam);
void imprimirVetor(int vetor[], int tam);
void imprimirVetorVersao2(int vetor[], int tam);

int main() {
  int numeros[TAM];
  preencherVetorImpares(numeros, TAM);
  // preencherVetorDigitacao(numeros, TAM);
  printf("vetor = ");
  imprimirVetorVersao2(numeros, TAM);
  if (estaOrdenado(numeros, TAM)) {
    printf("Vetor está ordenado!\n");
  } else {
    printf("Vetor não está ordenado!\n");
  }
  double media = calcularMediaVetor(numeros, TAM);
  printf("A média dos números digitados é %.2f\n", media);
  printf("\nImpressão de todos os números acima da média\n");
  imprimirValoresAcimaValor(numeros, TAM, media);
  realizarDiversasBuscas(numeros, TAM);
  return 0;
}

void preencherVetorDigitacao(int vetor[], int tam) {
  for (int i = 0; i < tam; i += 1) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &vetor[i]);
  }
}

// preenche vetor com números ímpares a partir do 11
void preencherVetorImpares(int vetor[], int tam) {
  for (int i = 0; i < tam; i += 1) {
    vetor[i] = 2 * i + 11;
  }
}

double calcularMediaVetor(int vetor[], int tam) {
  double soma = 0.0;
  for (int i = 0; i < tam; i += 1) {
    soma += vetor[i];
  }
  return soma / tam;
}

void imprimirValoresAcimaValor(int vetor[], int tam, double valor) {
  for (int i = 0; i < tam; i += 1) {
    if (vetor[i] > valor) {
      printf("vetor[%d] = %d\n", i + 1, vetor[i]);
    }
  }
}

int buscaSequencial(int vetor[], int tam, int x) {
  for (int i = 0; i < tam; i += 1) {
    if (vetor[i] == x) {
      return i;
    }
  }
  return -1;
}

void realizarDiversasBuscas(int vetor[], int tam) {
  int num, opcao;
  do {
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &num);
    int pos = buscaSequencial(vetor, tam, num);
    if (pos != -1) {
      printf("Número %d foi encontrado na posição %d\n", num, pos + 1);
    } else {
      printf("Número %d não foi encontrado!\n", num);
    }
    printf("Deseja fazer uma nova busca (0/1)? ");
    scanf("%d", &opcao);
  } while (opcao == 1);
}

int estaOrdenadoCrescente(int vetor[], int tam) {
  for (int i = 1; i < tam; i += 1) {
    if (vetor[i] < vetor[i - 1]) {
      return 0;
    }
  }
  return 1;
}

int estaOrdenadoDecrescente(int vetor[], int tam) {
  for (int i = 1; i < tam; i += 1) {
    if (vetor[i] > vetor[i - 1]) {
      return 0;
    }
  }
  return 1;
}

int estaOrdenado(int vetor[], int tam) {
  return estaOrdenadoCrescente(vetor, tam) ||
         estaOrdenadoDecrescente(vetor, tam);
}

void imprimirVetor(int vetor[], int tam) {
  printf("{ ");
  for (int i = 0; i < tam; i += 1) {
    if (i != tam - 1) {
      printf("%d, ", vetor[i]);
    } else {
      printf("%d ", vetor[i]);
    }
  }
  printf("}\n");
}

void imprimirVetorVersao2(int vetor[], int tam) {
  printf("{");
  if (tam > 0) {
    printf(" %d", vetor[0]);
  }
  for (int i = 1; i < tam; i += 1) {
    printf(", %d", vetor[i]);
  }
  printf(" }\n");
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     