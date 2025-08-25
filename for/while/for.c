#include <stdio.h>

// #define MIN 1
// #define MAX 5

const int MIN = 1;
const int MAX = 5;

int main() {
  printf("Contagem de %d a %d\n", MIN, MAX);
  for (int i = MIN; i <= MAX; i += 1){
    printf("%d\n", i);
  }

  printf("\nContagem de %d a %d\n", MAX, MIN);
  for (int i = MAX; i >= MIN; i -= 1) {
    printf("%d\n", i);
  }

  return 0;
}