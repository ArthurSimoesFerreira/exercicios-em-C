#include <stdio.h>
 
int main(void) {
 
    int reps, x , y;
    int soma = 0;
    scanf("%d", &reps);
    for(int i = 0; i<= reps; i++) {
        scanf("%d %d", &x, &y);
        for(int j = (x + 1); j < y; j += 2) {
            soma += j;
        }
        printf("%d\n", soma);
        soma = 0;
    }
 
    return 0;
}