#include <stdio.h>

void pa(int a1, int razao, int qntd) {
  if (qntd == 1)
    printf("%d\n", a1);
  if (qntd > 1) {
    printf("%d, ", a1);
    pa(a1 + razao, razao, qntd - 1);
  }
}

int main(void) {
  int a1, razao, qntd;
  printf("\nDigite o primeiro termo da PA: ");
  scanf("%d", &a1);

  printf("\nDigite a razao da PA: ");
  scanf("%d", &razao);

  do {
    printf("\nDigite a quantidade de termos da PA: ");
    scanf("%d", &qntd);
  } while (qntd <= 0);

  printf("\nPA = ");
  pa(a1, razao, qntd);

  return 0; 
}