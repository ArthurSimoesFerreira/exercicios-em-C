#include <stdio.h>

void imprimirSoma(int a, int b) {
  printf("\nA Soma %d + %d é: %d\n\n", a, b, (a + b));
}

void imprimirSubtracao(int a, int b) {
  printf("A Subtracao %d - %d é: %d\n\n", a, b, (a - b));
}

int divisao(int a, int b) {
  if (a < b)
    return 0;
  else
    return (divisao(a - b, b) + 1);
}

int multiplicacao(int a, int b) {
  if (b == 0)
    return 0;
  else
    return (multiplicacao(a, b - 1) + a);
}

int potenciacao(int a, int b) {
  if (b == 0)
    return 1;
  else
    return (potenciacao(a, b - 1) * a);
}

int main(void) {
  int a, b;
  do {
    printf("Digite dois números inteiros positivos: ");
    scanf("%d %d", &a, &b);
  } while (a <= 0 && b <= 0);

  imprimirSoma(a, b);

  imprimirSubtracao(a, b);

  printf("A Divisão %d/%d é: %d\n\n", a, b, divisao(a, b));

  printf("A Multiplicação %d * %d é: %d\n\n", a, b, multiplicacao(a, b));

  printf("A Potenciacao %d^%d é: %d\n", a, b, potenciacao(a, b));

  return 0;
}