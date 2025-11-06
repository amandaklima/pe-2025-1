#include <stdio.h>

#define QTD 15

struct Ponto {
  double x, y;
};

void imprimirVetor(struct Ponto v[], int tam);
void inserirValor(struct Ponto v[], int *tam);
int buscaSequencial(struct Ponto v[], int tam, struct Ponto p);
void buscarValores(struct Ponto v[], int tam);
void insertionSort(struct Ponto v[], int tam);
void ordenarVetor(struct Ponto v [], int tam);

int main() {
  struct Ponto pontos[QTD];
  int tam = 0, opcao;

  do {
    printf("\n\nMENU\n");
    printf("1 - Inserir um ponto no vetor\n");
    printf("2 - Imprimir o vetor\n");
    printf("3 - Buscar pontos no vetor\n");
    printf("4 - Ordenar o vetor com Insertion Sort\n");
    printf("Digite a sua opção (0 p/ sair):\n");
    scanf("%d", &opcao);
    switch(opcao) {
      case 1:
        inserirValor(pontos, &tam);
        break;
      case 2:
        imprimirVetor(pontos, tam);
        break;
      case 3:
        buscarValores(pontos, tam);
        break;
      case 4:
        insertionSort(pontos, tam);
        break;
      default:
        if (opcao != 0) {
          printf("Opção inválida!\n");
        }
        break;
    }
  } while (opcao != 0);
  printf("\nEncerrando o programa...\n");
  return 0;
}

void imprimirPonto(struct Ponto p) {
  printf("(%.2f, %.2f)", p.x, p.y);
}

void imprimirVetor(struct Ponto v[], int tam) {
  printf("{");
  if (tam > 0) {
    printf(" ");
    imprimirPonto(v[0]);
  }
  for (int i = 1; i < tam; i += 1) {
    printf(", ");
    imprimirPonto(v[i]);
  }
  printf(" }\n");
}

void digitarPonto(struct Ponto *p) {
  printf("Digite o valor de x: ");
  scanf("%lf", &p->x);
  printf("Digite o valor de y: ");
  scanf("%lf", &p->y);
}

void inserirValor(struct Ponto v[], int *tam) {
  if (*tam >= QTD) {
    printf("\nVetor cheio!\n");
    return;
  }

  digitarPonto(&v[*tam]);
  *tam += 1;
}

int buscaSequencial(struct Ponto v[], int tam, struct Ponto p) {
  for (int i = 0; i < tam; i += 1) {
    if (v[i].x == p.x && v[i].y == p.y) {
      return i;
    }
  }
  return -1;
}

void buscarValores(struct Ponto v[], int tam) {
  char opcao;
  struct Ponto valor;
  do {
    printf("Digite o ponto a ser buscado:\n");
    digitarPonto(&valor);
    int pos = buscaSequencial(v, tam, valor);

    printf("Ponto ");
    imprimirPonto(valor);
    if (pos != -1) {
      printf(" foi encontrado na posição % d\n ", pos + 1);
    } else {
      printf(" não foi encontrado no vetor !\n ");
    }
    printf("Quer realizar outra busca (s/n):\n");
    scanf("%c", &opcao); // lê o ENTER da digitação anterior
    scanf("%c", &opcao);
  } while (opcao == 's');
}

int pontoCmp (struct Ponto p1 , struct Ponto p2){
    int result = p1.x - p2.x;
    if (result == 0){
        result = p1.y - p2.y;
    }

}

void insertionSort(struct Ponto v[], int tam) {
   for (int i = 1; i <= tam - 1; i += 1) {
     int Ponto chave = v[i];
     int j = i;
      //while (j > 0 && (chave.x < [j - 1].x || (chave.x ==v [j-1].x) && chave.y < y [j - 1].y)) {
      while (j > 0 && pontoCmp (chave, v[j - 1]) <0 ) { 
      v[j] = v[j - 1];
      j = j - 1;
    }
     v[j] = chave;
   }
}