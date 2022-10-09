#include <stdio.h>

int main(void) {
  int soma = 0, maior = 0, menor = 0, i, estoque;

  for (i = 0; i < 30; i++) {
    estoque = 0;
    printf("Digite o estoque do dia %d: ", i + 1);
    scanf("%d", &estoque);
    soma += estoque;
    if (estoque > maior)
      maior = estoque;
    if (estoque < menor || i == 0)
      menor = estoque;
  }
  printf("\n\nA Média do estoque é: %f", soma / 30.0);
  printf("\nO menor estoque foi de: %d", menor);
  printf("\nO maior estoque foi de: %d\n", maior);

  return 0;
}  