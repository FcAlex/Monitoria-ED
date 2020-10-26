#include <stdio.h>
#include <stdlib.h>

typedef struct node No;

struct node { 
   int vertice; 
   No *next; 
};

typedef struct grafo {
  int n;      /* N�mero de n�s */
  No **lista;  /* Matriz (a ser alocada dinamicamente) */
} Grafo;

void cria_grafo(Grafo* g, int n)  { 
    g->lista = malloc(sizeof(No));
    g->n = n;
    g->lista = malloc( n * sizeof (No));
    for (int i = 0; i < n; i++) 
        g->lista[i] = NULL;
}

int inserirNo (No **c, int elem) {
	No *nw = malloc(sizeof(No));
	if(nw == NULL) return 0;

	nw->vertice = elem;
	nw->next = *c;
	*c = nw;

	return 1;
}

No* buscarNo (No *c, char valor) {
	No *p = c;
  	while (p != NULL) {
  		if(p->vertice == valor) return p;
  		p = p->next;
  	}
  	free(p);
  	return NULL;
}

void inserir_grafo(Grafo* g, int u, int v) { 
    if (buscarNo(g->lista[u], v) != NULL) return;
    
    inserirNo(&(g->lista[u]), v);
    inserirNo(&(g->lista[v]), u);
}

int removerNo(No **lst, int valor)
{
	No *anterior = NULL;
	No *p = *lst;
	while (p != NULL && p->vertice != valor) {
		anterior = p;
		p = p->next;
	}
	
	if (p == NULL)
		return 0;


	if (anterior == NULL)
		*lst = p->next;
	else
		anterior->next = p->next; 

	free(p);
	free(anterior);
}

void remover_grafo(Grafo* g, int u, int v) { 
    removerNo(&(g->lista[u]), v);
    removerNo(&(g->lista[v]), u);
}

void imprimirNo(No *ls) {
	No *p;
	p = ls;
  	while (p != NULL) {
  		printf("%i", p->vertice);
  		p = p->next; 
  	}
  	free(p);
}

void imprimir(Grafo *g, int n) {
    for(int j = 0; j < n; j++) {
        printf("%i -> ", j);
        imprimirNo(g->lista[j]);
        printf("\n");
    }
}

int main() {
    Grafo *g = malloc(sizeof(Grafo));
    cria_grafo(g, 3);
    inserir_grafo(g, 1, 2);
    //remover_grafo(g, 2, 1);
    imprimir(g, 3);
    //remover_grafo(g, 0, 1);
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            printf("%i ", g->mat[i][j]);
//        }
//        printf("\n");
//    }

    return 0;
}
