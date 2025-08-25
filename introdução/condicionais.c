#include <stdio.h>

int main() {
  int idade;

  printf("Digite a sua idade:\n");
  scanf("%d", &idade);
  printf("idade = %d\n", idade);

  if (idade >= 18) {
    printf("Você pode comprar bebida alcóolica!\n");
  } else {
    printf("Você não pode comprar bebida alcóolica!\n");
  }

  if (idade < 16) {
    printf("Você ainda não tem idade para votar!\n");
  } else if (idade < 18) {
    printf("Já tem idade para votar, mas, é facultativo. Se tirar o título de eleitor, passa a ser obrigatório!\n");
  } else if (idade < 70) {
    printf("Nesta idade, o voto é obrigatório!\n");
  } else {
    printf("Nesta idade, mesmo tendo título de eleitor, o voto é facultativo!\n");
  }

  return 0;
}
