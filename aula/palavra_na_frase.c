#include <string.h>
#include <stdio.h>

int estaNaFrase(char *frase, char *palavra){
  int i, letra = 0, tamFrase;
  tamFrase = strlen(frase);
  
  for(i=0; i<tamFrase; i++) {
    if(letra == strlen(palavra))
      return 1;
    if(frase[i] == palavra[letra])
      letra += 1;
  }
  return 0;
}

int main(void){
  char frase[100], palavra[15];

  printf("\nDigite a frase: ");
  scanf(" %[^\n]s", frase);
    
  printf("Digite a palavra: ");
  scanf(" %[^\n]s", palavra);

  if(estaNaFrase(frase, palavra)){
    printf("A ocorre em B");
  } else {
    printf("B ocorre em A");
  }
  return 0;
}