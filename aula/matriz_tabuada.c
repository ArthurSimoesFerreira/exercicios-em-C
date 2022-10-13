#include <stdio.h>
#include <stdlib.h>

void preencherMatriz(int **matriz, int n) {
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      matriz[i][j] = (i + 1) * (j + 1);
}

void escreverMatriz(int **matriz, int n) {
  int i, j;
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }
}

int main(void) {
  int n, **matriz, i;

  printf("Digite o número da tabuada: ");
  scanf("%d", &n);
  matriz = ((int **)malloc(sizeof(int) * n));
  for (i = 0; i < n; i++)
    matriz[i] = (int *)malloc(sizeof(int) * n);

  preencherMatriz(matriz, n);

  escreverMatriz(matriz, n);

  return 0;
}