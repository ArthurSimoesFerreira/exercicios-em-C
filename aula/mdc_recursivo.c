#include <stdio.h>

int mdc(int x, int y) {
  if(y <= x && x%y == 0)
    return y;
  else if(x < y)
    return mdc(y, x);
  else
    return mdc(y, x % y);
}

int main(void) {
  int x, y;
  printf("Digite dois números inteiros: ");
  scanf("%d %d", &x, &y);
  printf("\nO mdc é: %d\n", mdc(x, y));
  return 0;
}