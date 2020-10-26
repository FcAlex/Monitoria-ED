#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} No;

typedef struct lista {
    struct no *inicio;
    int tam;
} Lista;

Lista *create() {
    Lista *l = malloc(sizeof(Lista));

    if(l != NULL) {
        l->inicio = NULL;
        l->tam = 0;
    }
}

int add(Lista *l, int valor) {
    No *no = malloc(sizeof(No));

    no->valor = valor;

    if (l->inicio == NULL){
        no->prox = no;
        no->ant = no;
    } else {
        no->prox = l->inicio;
        no->ant = l->inicio->ant;

        l->inicio->ant->prox = no;
        l->inicio->ant = no;
    }

    l->inicio = no;
    l->tam++;

    return 1;
}

int busca(Lista *lista, int valor) {
    No *aux = lista->inicio;
    int c = 0;

    if(aux == NULL) return -1;

    do {
        if(aux->valor == valor) return c;
        c++;
        aux = aux->prox;
    } while(aux != lista->inicio);

    return -1;
}

void imprimir(Lista *l) {
    No *aux = l->inicio;

    if(aux == NULL) {
        printf("LISTA VAZIA");
        return;
    }

    do {
        printf("%d ", aux->valor);
        aux = aux->prox;
    } while(aux != l->inicio);
}

int rmv(Lista *l, int valor) {
    int pos = busca(l, valor);
    if(pos < 0) return 0;

    if(l->inicio == NULL) return 0;
    else if(l->tam == 1) { // possui um elemento
        l->inicio = NULL;
        l->tam = 0;
        return 1;
    }

    No *aux = l->inicio;

    int i;
    for(i = 0; i < pos; i++) aux = aux->prox;

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;

    l->tam--;
    free(aux);
    return 1;
}

int main() {

    Lista *l = create();
    add(l, 3);

    rmv(l, 3);

    imprimir(l);

    return 0;
}
