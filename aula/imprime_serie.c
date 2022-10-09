#include <stdio.h>

void imprimeSerie(int atual, int fim, int intervalo) {
  if (atual + intervalo < fim) {
    printf("%d ", atual);
    imprimeSerie(atual + intervalo, fim, intervalo);
  } else {
    printf("%d\n", atual);
  }
}

int main(void) {
  int i, j, k;
  printf("Digite dois números: ");
  scanf("%d %d", &i, &j);
  if (i == j) {
    printf("\nNúmeros são iguais\n");
  } else {
    printf("\nDigite o Intervalo: ");
    scanf("%d", &k);
    if (i < j)
      imprimeSerie(i + k, j, k);
    else if (i > j)
      imprimeSerie(j + k, i, k);
  }
  return 0;
}