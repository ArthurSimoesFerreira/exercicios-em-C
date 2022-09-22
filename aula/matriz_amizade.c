#include <stdio.h>

void preencherMatriz(int N, int matriz[N][N]) {
  int i, j;
  printf("Digite A Matriz Amizade\n");
  printf("0 para não amigo\n");
  printf("1 para amigo\n");
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      if (i != j) {
        printf("A Pessoa %d se diz amigo(a) da pessoa %d?: ", i, j);
        scanf("%d", &matriz[i][j]);
      } else {
        matriz[i][j] = 0;
      }
    }
}

//
void verificarInconsistencias(int N, int matriz[N][N]) {
  int contador = 1, i = 0, j = 1, inconsistencias = 0;
  while (i < N) {
    while (j < N) {
      if (matriz[i][j] != matriz[j][i])
        inconsistencias += 1;
      j += 1;
    }
    i += 1;
    contador += 1;
    j = contador;
  }
  printf("A matriz tem %d inconsistencias", inconsistencias);
}

void escreverMatriz(int N, int matriz[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }
}

int main(void) {
  int N, inconsistencias;
  printf("Quantas Pessoas Estão Participando: ");
  scanf("%d", &N);
  int matriz[N][N];
  preencherMatriz(N, matriz);
  printf("A matriz:\n");
  escreverMatriz(N, matriz);
  verificarInconsistencias(N, matriz);

  return 0;
}