#include <stdio.h>
#include <stdlib.h>

struct celula {
	char caracter;
	struct celula *prox;
	struct celula *ant;
};

typedef struct celula Celula;

Celula *inicializar () {
	return NULL;
}

int inserir (Celula **c, char elem) {
	Celula *nw = malloc(sizeof(Celula));
	if(nw == NULL) return 0;

	nw->caracter = elem;
	nw->prox = *c;
	nw->ant = NULL;

	if(*c != NULL) (*c)->ant = nw;
	*c = nw;

	return 1;
}

void imprimirR(Celula *c) {
	Celula *p = c;

	while(p->prox != NULL) p = p->prox;

  	while (p != NULL) {
  		printf("%c\n", p->caracter);
  		p = p->ant;
  	}
  	free(p);
}

void imprimir(Celula *ls) {
	Celula *p;
	p = ls;
  	while (p != NULL) {
  		printf("%c\n", p->caracter);
  		p = p->prox; 
  	}
  	free(p);
}

int main(int argc, char const *argv[])
{
	Celula *lista = inicializar();
	inserir(&lista, '1');
	inserir(&lista, '2');
	inserir(&lista, '3');

	imprimirR(lista);
	return 0;
}

