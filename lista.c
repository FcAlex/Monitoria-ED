#include <stdio.h>
#include <stdlib.h>

struct Celula {
	char caracter;
	struct Celula *prox;
};

typedef struct Celula Celula;

Celula *inicializar () {
	return NULL;
}

int inserir (Celula **c, char elem) {
	Celula *nw = malloc(sizeof(Celula));
	if(nw == NULL) return 0;

	nw->caracter = elem;
	nw->prox = *c;
	*c = nw;

	return 1;
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

Celula* buscar (Celula *c, char valor) {
	Celula *p = c;
  	while (p != NULL) {
  		if(p->caracter == valor) return p;
  		p = p->prox;
  	}
  	free(p);
  	return NULL;
}

int remover(Celula **lst, char valor)
{
	Celula *anterior = NULL;
	Celula *p = *lst;
	while (p != NULL && p->caracter != valor) {
		anterior = p;
		p = p->prox;
	}
	
	if (p == NULL)
		return 0;


	if (anterior == NULL)
		*lst = p->prox;
	else
		anterior->prox = p->prox; 

	free(p);
	free(anterior);
}

int main(int argc, char const *argv[])
{
	Celula *lista = inicializar();
	inserir(&lista, '1');
	inserir(&lista, '2');
	inserir(&lista, '3');

	// remover(&lista, '3');	
	printf("--> %c\n", buscar(lista, '2')->caracter);

	imprimir(lista);
	return 0;
}

