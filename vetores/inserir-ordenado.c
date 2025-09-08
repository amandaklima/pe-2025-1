#include <stdio.h>

#define TAM 7

void preencherVetorDigitacao(int vetor[], int tam);
void inserirOrdenado(int vetor[], int tam, int x);
double calcularMediaVetor(int vetor[], int tam);
void imprimirValoresAcimaValor(int vetor[], int tam, double valor);
void imprimirVetor(int vetor[], int tam);
int buscaSequencial(int vetor[], int tam, int x);
void realizarDiversasBuscas(int vetor[], int tam);

int main() {
  int numeros[TAM];
  preencherVetorDigitacao(numeros, TAM);
  double media = calcularMediaVetor(numeros, TAM);
  printf("A média dos números digitados é %.2f\n", media);
  printf("\nImpressão de todos os números acima da média\n");
  imprimirValoresAcimaValor(numeros, TAM, media);
  realizarDiversasBuscas(numeros, TAM);
  return 0;
}

void inserirOrdenado(int vetor[], int tam, int x) {
  int pos = tam;
  while (pos > 0 && x < vetor[pos - 1]) {
    vetor[pos] = vetor[pos - 1];
    pos -= 1;
  }
  vetor[pos] = x;
}

void preencherVetorDigitacao(int vetor[], int tam) {
  int num;
  for (int i = 0; i < tam; i += 1) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &num);
    // vetor[i] = num; // insere na última posição livre do vetor
    inserirOrdenado(vetor, i, num);
    printf("vetor = [ ");
    imprimirVetor(vetor, i + 1);
    printf("]\n");
  }
}

double calcularMediaVetor(int vetor[], int tam) {
  double soma = 0.0;
  for (int i = 0; i < tam; i += 1) {
    soma += vetor[i];
  }
  return soma / tam;
}

void imprimirVetor(int vetor[], int tam) {
  for (int i = 0; i < tam; i += 1) {
    printf("%d ", vetor[i]);
  }
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

int buscaBinaria(int vetor[], int tam, int x) {
  int inicio = 0, fim = tam - 1, meio;
  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    if (x == vetor[meio]) {
      return meio;
    } else if (x < vetor[meio]) {
      fim = meio - 1;
    } else {
      inicio = meio + 1;
    }
  }
  // índice negativo para informar que não encontrou
  // retorna o índice de onde deveria inserir esse número (precisa
  // inverter e subtrair 1 no final)
  return -(meio + 1);  
}

void realizarDiversasBuscas(int vetor[], int tam) {
  int num;
  char opcao;
  do {
    printf("vetor = [ ");
    imprimirVetor(vetor, tam);
    printf("]\n");
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &num);
    int pos = buscaBinaria(vetor, tam, num);
    if (pos >= 0) {
      printf("Número %d foi encontrado na posição %d\n", num, pos + 1);
    } else {
      printf("Número %d não foi encontrado, deve inserir na posição %d!\n",
        num, -(pos + 1) + 1);
    }
    printf("Deseja fazer uma nova busca (s/n)? ");
    scanf("%c", &opcao); // essa leitura guarda o ENTER da digitação anterior
    scanf("%c", &opcao); // essa leitura realmente guarda o 's' ou 'n'
  } while (opcao == 's');
}

