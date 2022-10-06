#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Ler o número
// Verificar se é palíndromo

int palindromo(int num) {
  char numChar[10];
  int tamChar, i;

  sprintf(numChar, "%d", num);

  tamChar = strlen(numChar);

  for (i = 0; i < tamChar - 1; i++) {
    if (numChar[i] != numChar[tamChar - 1 - i])
      return 0;
  }
  return 1;
}

int main(void) {
  int num, i;

  printf("Digite um número: ");
  scanf(" %d", &num);

  while (num > 0) {
    if (palindromo(num))
      printf("\nÉ um palíndromo");
    else
      printf("\nNão é um palíndromo");

    printf("\nDigite um outro número: ");
    scanf(" %d", &num);
  }
}