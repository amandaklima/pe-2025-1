#include <stdio.h>

const int TAM = 10;

int inserirVetor(int v[], int n);
int imprimirVetor(int v[], int n);
int inserirOrdenado(int v[], int n, int x);
int criarVetorOrdenado(int vetOrig[], int vetOrd[], int tamVetOrig);
int buscaBinaria(int v[], int n, int x);

int main() {
  int vetOrig[TAM], vetOrd[100];
  int tamVetOrig = 0, tamVetOrd = 0;
  int opcao, num, pos;
  do {
    printf("\nMENU\n\n");
    printf("1 - Inserir 1 valor no vetor\n");
    printf("2 - Criar vetor ordenado\n");
    printf("3 - Busca Binária\n");
    printf("Digite sua opcao (0 p/ finalizar): ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      tamVetOrig = inserirVetor(vetOrig, tamVetOrig);
      printf("vetOrig = ");
      imprimirVetor(vetOrig, tamVetOrig);
      break;
    case 2:
      tamVetOrd = criarVetorOrdenado(vetOrig, vetOrd, tamVetOrig);
      break;
    case 3:
      tamVetOrd = criarVetorOrdenado(vetOrig, vetOrd, tamVetOrig);
      printf("Digite um numero para realizar a busca: ");
      scanf("%d", &num);
      pos = buscaBinaria(vetOrd, tamVetOrd, num);
      if (pos != -1) {
        printf("Achou o valor %d na posicao %d\n", num, pos + 1);
      } else {
        printf("Nao achou o valor %d\n", num);
      }
      break;
    default:
      if (opcao != 0) {
        printf("Opcao invalida!\n");
      }
      break;
    }
  } while (opcao != 0);
  return 0;
}

int imprimirVetor(int v[], int n) {
  for (int i = 0; i < n; i += 1) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int inserirVetor(int v[], int n) {
  if (n < TAM) {
    printf("Digite um valor inteiro: ");
    scanf("%d", &v[n]);
    return n + 1;
  } else {
    printf("Vetor cheio!\n");
    return n;
  }
}

int inserirOrdenado(int v[], int n, int x) {
  int pos = n;
  if (pos < TAM) {
    while (pos > 0 && v[pos - 1] > x) {
      v[pos] = v[pos - 1];
      pos -= 1;
    }
    v[pos] = x;
    return n + 1;
  } else {
    printf("Vetor cheio!\n");
    return n;
  }
}

int criarVetorOrdenado(int vetOrig[], int vetOrd[], int tamVetOrig) {
  int tamVetOrd = 0;
  for (int i = 0; i < tamVetOrig; i += 1) {
    tamVetOrd = inserirOrdenado(vetOrd, tamVetOrd, vetOrig[i]);
  }
  printf("vetOrig = ");
  imprimirVetor(vetOrig, tamVetOrig);
  printf("vetOrd = ");
  imprimirVetor(vetOrd, tamVetOrd);
  return tamVetOrd;
}

int buscaBinaria(int v[], int n, int x) {
  int inicio = 0, fim = n - 1, meio;
  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (v[meio] == x) {
      return meio;
    } else if (x < v[meio]) {
      fim = meio - 1;
    } else {
      inicio = meio + 1;
    }
  }
  return -1;
}