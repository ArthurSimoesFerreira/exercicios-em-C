#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void escreverPorcentagens(int nJogadas, int *vetor) {
  int i;
  for (i = 0; i < 11; i++) {
    printf("A porcentagem de aparição do número %d é: ", i+2);
    printf("%.2f%%\n\n", (vetor[i] * 1.0 / nJogadas) * 100);
  }
}


int main(void) {
  int i, nJogadas, dado1, dado2, soma, vetor[11];
  for (i = 0; i < 11; i++)
    vetor[i] = 0;
  printf("Digite o número de jogadas: ");
  scanf("%d", &nJogadas);
  srand(time(NULL));
  printf("\nDados jogados:\n");
  for (i = 0; i < nJogadas; i++) {
    dado1 = rand() % 6 + 1;
    dado2 = rand() % 6 + 1;
    printf("(%d,%d)\n", dado1, dado2);
    soma = dado1 + dado2;
    vetor[soma - 2] += 1;
  }
  escreverPorcentagens(nJogadas, vetor);
  return 0;
}
