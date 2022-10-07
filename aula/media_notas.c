// Função: recebe 6 notas -> Descarta a maior e a menor
// -> Calcula a média
#include <stdio.h>
#include <stdlib.h>

float fazerMedia(float *notas, int posMax, int posMin) {
  int i;
  float soma;

  for (i = 0; i < 6; i++) {
    if (i != posMax && i != posMin)
      soma += notas[i];
  }
  return soma / 4.0;
}

int main(void) {
  float notas[6], notaMax = 0, notaMin = 10, media;
  int i, j, posMax, posMin;
  // Loop para os 30 alunos
  for (i = 0; i < 30; i++) {
    printf("\nAluno %d: ", i + 1);

    // Loop para as 6 notas
    for (j = 0; j < 6; j++) {
      printf("\nDigite a nota %d: ", j + 1);
      scanf("%f", &notas[j]);

      if (notas[j] >= notaMax) {
        notaMax = notas[j];
        // Grava a posição da maior nota
        posMax = j;
      } else if (notas[j] <= notaMin) {
        notaMin = notas[j];
        // Grava a posição da menor nota
        posMin = j;
      }
    }
    media = fazerMedia(notas, posMax, posMin);
    printf("\nA média das notas do aluno é %.2f\n", media);
  }
  return 0;
}