#include <stdio.h>
int testeNum(int N) {
  int esq, dir, valor;

  esq = N / 100;
  dir = N % 100;
  valor = (esq + dir) * (esq + dir);
  if (valor == N)
    return 1;
  else
    return 0;
}
int main(void) {
  int i;
  for (i = 1000; i <= 9999; i++) {
    if (testeNum(i))
      printf("\n%d satisfaz a prppriedade\n", i);
  }
  return 0;
}