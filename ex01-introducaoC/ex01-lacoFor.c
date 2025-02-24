#include <stdio.h>
//#define MAX_NUM 10
const int MAX_NUM = 10;

int main() {
  int num;
  printf("Numeros ate 10\n");
  for (num = 1; num <= MAX_NUM; ++num) {
    printf("%d\n", num);
  }
  printf("\nImpares COM IF\n");
  for (num = 1; num <= MAX_NUM; ++num) {
    if (num % 2 != 0) {
      printf("%d\n", num);
    }
  }
  printf("\nImpares SEM IF\n");
  for (num = 1; num <= MAX_NUM; num += 2) {
    printf("%d\n", num);
  }
  return 0;
}