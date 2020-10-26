#include <stdio.h>	
#include <stdlib.h>

struct pilha {
	int total;
	int topo;
	char *caracter;
};

typedef struct pilha Pilha;

Pilha* inicializar (int tot) {
	Pilha* aux = malloc(sizeof(Pilha));
	aux->caracter = malloc(sizeof(char)*tot);

	aux->topo = -1;
	aux->total = tot;

	return aux;
}

int push (Pilha *p, char valor) {
	if(p->topo == p->total - 1) {
		printf("Overflow\n");
		return 0;
	}

	p->topo++;
	p->caracter[p->topo] = valor;
	return 1;
}

char pop (Pilha *p) {
	if(p->topo == -1) {
		printf("UnderFlow\n");
		return -1;
	}
	return p->caracter[p->topo--];
}

int main()
{
	Pilha *p = inicializar(10);
	push(p, '5');
	push(p, '8');
	push(p, '7');
	push(p, '1');

	printf("%c\n", pop(p));
	printf("%c\n", pop(p));
	printf("%c\n", pop(p));

	return 0;
}