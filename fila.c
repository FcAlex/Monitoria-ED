#include <stdio.h>
#include <stdlib.h>

struct fila {
	int total;
	int inicio;
	int fim;
	char *caracter;
};

typedef struct fila Fila;

Fila* inicializar (int tot) {
	Fila* aux = malloc(sizeof(Fila));
	aux->caracter = malloc(sizeof(char)*tot);
	aux->inicio = aux->fim = 0;
	aux->total = tot;

	return aux;
}

int enqueue(Fila *f, char valor) {
	int inc = (f->fim + 1)%f->total;
	if(inc == f->inicio) return 0;

	f->caracter[f->fim] = valor;
	f->fim = inc;
	return 1; 
}

char dequeue(Fila *f) {
	if(f->inicio == f->fim) return -1; // Fila Vazia

	char c = f->caracter[f->inicio];
	f->inicio = (f->inicio + 1) % f->total;;
	return c;
}

void imprimir(Fila *f) {
	for (int i = f->inicio; i < f->fim; i = (i+1)%f->total) {
		printf("fila[%i] = %c\n", i, f->caracter[i]);
	}
}

int main() {
	Fila *f = inicializar(4);
	enqueue(f, 'A');
	enqueue(f, 'B');
	enqueue(f, 'C');

	dequeue(f);
	dequeue(f);
	dequeue(f);

	imprimir(f);
	return 0;
}