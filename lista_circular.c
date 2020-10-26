#include <stdio.h>
#include <stdlib.h>

struct celula {
	char caracter;
	struct celula *prox;
};

typedef struct celula Celula;

Celula *inicializar () {
	return NULL;
}

int inserir (Celula **c, char elem) {
	Celula *nw = malloc(sizeof(Celula));
	if(nw == NULL) return 0;
	nw->caracter = elem;

	if(*c == NULL) {
		nw->prox = nw;
	} else {
		nw->prox = (*c)->prox;
		(*c)->prox = nw;
	}

	*c = nw;

	return 1;
}

void imprimir(Celula *no) {
	Celula *p = no;

	do {
		printf("%c\n", p->caracter);
		p = p->prox;
	} while (p != no);
}

int main(int argc, char const *argv[])
{
	Celula *lista = inicializar();
	inserir(&lista, '1');
	inserir(&lista, '2');
	inserir(&lista, '3');

	imprimir(lista);
	return 0;
}