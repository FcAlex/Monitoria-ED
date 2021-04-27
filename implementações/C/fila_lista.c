#include <stdio.h>
#include <stdlib.h>

struct celula {
	char caracter;
	struct celula *prox;
};

typedef struct celula Celula;

struct fila {
	Celula *inicio;
	Celula *fim;
};

typedef struct fila Fila;

Fila *inicializar() {
	Fila *f = malloc(sizeof(Fila));

	f->inicio = f->fim = 0;
	return f;
}

int enqueue(Fila *f, char valor) {
	Celula *aux = (Celula*) malloc(sizeof(Celula));
	aux->caracter = valor;
	aux->prox = NULL;

	if(f->fim != NULL)
		f->fim->prox = aux;

	f->fim = aux;

	if (f->inicio == NULL)
		f->inicio = f->fim;
}


char dequeue(Fila *f) {
	if (f->fim==NULL) // esta vazia
		return -1;

	char v = f->inicio->caracter;

	Celula *lixo = f->inicio;

	f->inicio = f->inicio->prox;
	if (f->inicio == NULL)
		f->fim = NULL;

	free(lixo);
	return v;
}

void imprimir(Fila *f) {
	Celula *p = f->inicio;
  	while (p != NULL) {
  		printf("%c\n", p->caracter);
  		p = p->prox; 
  	}
  	free(p);
}

int main(int argc, char const *argv[]) {
	Fila *f = inicializar();
	enqueue(f, 'A');
	enqueue(f, 'B');
	enqueue(f, 'C');
	enqueue(f, 'D');

	dequeue(f);

	imprimir(f);
	return 0;
}