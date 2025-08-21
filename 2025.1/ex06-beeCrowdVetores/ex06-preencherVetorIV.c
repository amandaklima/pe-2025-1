/*
Neste problema você deverá ler 15 valores colocá-los em 2 vetores 
conforme estes valores forem pares ou ímpares. Só que o tamanho de
cada um dos dois vetores é de 5 posições. Então, cada vez que um dos
dois vetores encher, você deverá imprimir todo o vetor e utilizá-lo
novamente para os próximos números que forem lidos. Terminada a leitura,
deve-se imprimir o conteúdo que restou em cada um dos dois vetores,
imprimindo primeiro os valores do vetor impar. Cada vetor pode ser
preenchido tantas vezes quantas for necessário.

Entrada
A entrada contém 15 números inteiros.

Saída
Imprima a saída conforme o exemplo abaixo.
*/

#include <stdio.h>

const int QTD_NUMEROS = 15;
const int TAM_VETOR = 5;

void imprimir(int v[], int n, char *nomeVetor);

int main() {
  int par[TAM_VETOR], impar[TAM_VETOR];
  int num, qtdPares = 0, qtdImpares = 0;
  for (int i = 0; i < QTD_NUMEROS; i += 1) {
    scanf("%d", &num);
    if (num % 2 == 0) {
      par[qtdPares] = num;
      qtdPares += 1;
      if (qtdPares == TAM_VETOR) {
        imprimir(par, qtdPares, "par");
        qtdPares = 0;
      }
    } else {
      impar[qtdImpares] = num;
      qtdImpares += 1;
      if (qtdImpares == TAM_VETOR) {
        imprimir(impar, qtdImpares, "impar");
        qtdImpares = 0;
      }
    }
  }
  imprimir(impar, qtdImpares, "impar");
  imprimir(par, qtdPares, "par");
}

void imprimir(int v[], int n, char *nomeVetor) {
  for (int i = 0; i < n; i += 1) {
    printf("%s[%d] = %d\n", nomeVetor, i, v[i]);
  }
}