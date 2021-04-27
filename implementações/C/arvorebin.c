#include <stdlib.h>
#include <stdio.h>

struct no {
	char valor;
	struct no *dir;
	struct no *esq;
};
typedef struct no No;

No *inicializar() {
	return NULL;
}

No* inserir(No *r, int v) {
	if (r == NULL) {
		r = malloc (sizeof(No));
		r->valor = v;
		r->esq = r->dir = NULL;
	}
	
	else if (v < r->valor)
		r->esq = inserir(r->esq,v);
	else
		r->dir = inserir(r->dir,v);
	return r;
}

No* buscar(No *No, int v) {
	if (No == NULL) return NULL;
	else if (No->valor == v) return No;
	else if (No->valor < v) return buscar (No->esq, v);
	else return buscar (No->dir, v);
}


void imprime (No* a) {
	if (a != NULL) {
		imprime(a->esq);
		printf("%d\n",a->valor);
		imprime(a->dir);
	}
}

No* retira (No* arv, int v) {
	if (arv == NULL) return NULL;
	else if (arv->valor > v) arv->esq = retira(arv->esq, v);
	else if (arv->valor < v) arv->dir = retira(arv->dir, v);
	else {
		if (arv->esq == NULL) {
			No* t = arv->dir;
			free (arv);
			return t;
		} else if (arv->dir == NULL) {
			No* t = arv->esq;
			free (arv);
			return t;
		} else {
			No* pai = arv;
			No* f = arv->esq;
			while (f->dir != NULL) {
				pai = f;
				f = f->dir;
			}
			arv->valor = f->valor;
			f->valor = v;
			arv->esq = retira(arv->esq,v);
		}
	}
	return arv;
}

int main(){
	No *root = NULL; 
    root = inserir(root, 50); 
    inserir(root, 30); 
    inserir(root, 20); 
    inserir(root, 40); 
    inserir(root, 70); 
    inserir(root, 60); 
    inserir(root, 80);

    retira(root, 30);

    imprime(root);
	return 0;
}