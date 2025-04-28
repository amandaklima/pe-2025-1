#include <stdio.h>

int main() {
  int *p;
  int a = 10, b = 15, c = 20;
  printf("&a = %p - &b = %p - &c = %p\n", &a, &b, &c);
  printf("a = %d - b = %d - c = %d\n", a, b, c);
  // via aritmética de ponteiros: só vai funcionar se a, b e c forem
  // criadas em posições de memória adjacentes
  p = &a;
  *p += 1;
  p += 1;
  *p += 1;
  p += 1;
  *p += 1;
  printf("&a = %p - &b = %p - &c = %p\n", &a, &b, &c);
  printf("a = %d - b = %d - c = %d\n", a, b, c);
  // via atribuição dos endereços de memória de cada variável
  // assim, sempre irá funcionar
  p = &a;
  *p += 1;
  p = &b;
  *p += 1;
  p = &c;
  *p += 1;
  printf("&a = %p - &b = %p - &c = %p\n", &a, &b, &c);
  printf("a = %d - b = %d - c = %d\n", a, b, c);
  return 0;
}