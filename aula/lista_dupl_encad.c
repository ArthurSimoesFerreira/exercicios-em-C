#include <stdio.h>
#include <stdlib.h>

struct NO_sub {
  int info;
  struct NO_sub *proxSub;
};
typedef struct NO_sub sublista;

struct NO {
  int info;
  struct NO *prox;
  struct NO_sub *proxSub;
};
typedef struct NO lista;

int buscaLista(lista *L, int n, lista **pre) {
  lista *aux, *prel;
  aux = L->prox;
  prel = L;
  while ((aux != NULL) && (n > aux->info)) {
    prel = aux;
    aux = aux->prox;
  }
  (*pre) = prel;
  if ((aux != NULL) && ((aux->info) == n))
    return 1;
  return 0;
}

int buscaSubLista(sublista *LS, int n, sublista **preSub) {
  sublista *auxSub, *preSubl;
  auxSub = LS;
  preSubl = NULL;

  while ((auxSub != NULL) && (n > auxSub->info)) {
    preSubl = auxSub;
    auxSub = auxSub->proxSub;
  }
  (*preSub) = preSubl;
  if ((auxSub != NULL) && (n == auxSub->info))
    return 1;
  return 0;
}

void insereLista(lista *L, int n) {
  lista *el, *pre;
  if (!buscaLista(L, n, &pre)) {
    el = (lista *)malloc(sizeof(lista));
    el->info = n;
    el->prox = pre->prox;
    pre->prox = el;
    printf("\nElemento inserido!\n");
  } else
    printf("\nElemento ja Existe!\n");
}

void insereSubLista(lista *L, int familia, int n) {
  lista *pre, *aux;
  sublista *auxSub, *el, *preSub;

  if (buscaLista(L, familia, &pre)) {
    aux = pre->prox;
    auxSub = aux->proxSub;

    if (!buscaSubLista(auxSub, n, &preSub)) {
      el = (sublista *)malloc(sizeof(sublista));
      el->info = n;
      if (preSub == NULL) {
        el->proxSub = aux->proxSub;
        aux->proxSub = el;
      } else {
        el->proxSub = preSub->proxSub;
        preSub->proxSub = el;
      }
      printf("\nElemento inserido!\n");
    } else {
      printf("\nO número já existe!\n");
    }
  } else {
    printf("\nA família desse número não existe\n");
  }
}

void imprimeLista(lista *L) {
  sublista *auxT;

  while (L != NULL) {
    printf("\n%d: ", L->info);
    auxT = L->proxSub;
    while (auxT != NULL) {
      printf("%d ", auxT->info);
      auxT = L->proxSub;
    }
    L = L->prox;
  }
}

int menu() {
  int opcao;

  printf("\n\nDigite o número da opção desejada:\n\n");
  printf("1 -> Inserir elemento na lista\n");
  printf("2 -> Inserir elemento na sublista\n");
  printf("3 -> Imprimir a lista\n");
  printf("4 -> FIM\n");
  scanf("%d", &opcao);
  return opcao;
}

int main(void) {
  lista *L;
  int n, opcao, familia;

  L = (lista *)malloc(sizeof(lista *));
  L->prox = NULL;
  L->proxSub = NULL;

  printf("\nDigite o número que quer colocar na lista: ");
  scanf("%d", &n);
  while (n > 0) {
    if ((n % 10) == 0)
      insereLista(L, n);
    else
      printf("Elemento tem que ser múltiplo de 10");
    printf("\nDigite o número que quer colocar na lista: ");
    scanf("%d", &n);
  }
  do {
    opcao = menu();
    switch (opcao) {
    case 1:
      printf("\nDigite um número múltiplo de 10: ");
      scanf("%d", &n);
      if ((n % 10) == 0)
        insereLista(L, n);
      else
        printf("\nElemento tem que ser múltiplo de 10\n");
      break;
    case 2:
      printf("\nDigite um número para a sub-lista: ");
      scanf("%d", &n);
      if (n % 10 == 0)
        printf("\nO número é múltiplo de 10 e não pode ser inserido\n");
      else {
        familia = (n / 10) * 10;
        insereSubLista(L, familia, n);
      }
      break;
    case 3:
      imprimeLista(L);
      break;
    }
  } while (opcao != 4);
}