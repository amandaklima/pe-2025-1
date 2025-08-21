#include <stdio.h>

const int TAM = 4;

int main() {
  double v[] = { 1, 2, 3, 4 };
  printf("v = %p\n", v);
  for (int i = 0; i < TAM; i += 1) {
    printf("v[%d] = %f - (%p)\n", i, v[i], &v[i]);
  }
  printf("*v = %f\n", *v);
  printf("*(v + 1) = %f - (v + 1) = %p\n", *(v + 1), v + 1);
  return 0;
}