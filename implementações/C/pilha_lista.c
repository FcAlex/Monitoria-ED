#include <stdio.h>	
#include <stdlib.h>

struct pilha {
	char caracter;
	struct pilha *prox;
};

typedef struct pilha Pilha;

Pilha* inicializar() {
	return NULL;
}

int push( Pilha **p, char valor) {
	Pilha *nw = malloc(sizeof(Pilha));
	if(nw == NULL) return 0;

	nw->caracter = valor;
	nw->prox = *p;
	*p = nw;
	return 1;
}

char pop(Pilha** p) {
	if(*p == NULL) {
		printf("Underflow\n");
		exit(0);
	}

	Pilha *aux = *p;
	*p = (*p)->prox;
	char removido = aux->caracter;
	free(aux);
	return removido;
}

int main()
{
	Pilha *p = inicializar();
	push(&p, '5');
	push(&p, '8');
	push(&p, '7');
	push(&p, '1');

	printf("%c\n", pop(&p));
	printf("%c\n", pop(&p));
	printf("%c\n", pop(&p));
	return 0;
}