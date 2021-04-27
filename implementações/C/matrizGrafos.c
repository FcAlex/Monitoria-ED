#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
  int n;      /* N�mero de n�s */
  int **mat;  /* Matriz (a ser alocada dinamicamente) */
} Grafo;

void cria_grafo(Grafo* g, int n)  { 
    g->n = n;
    g->mat = malloc(n * sizeof (int));
    for (int i = 0; i < n; ++i)
        g->mat[i] = calloc(n, sizeof (int));
}

void inserir_grafo(Grafo* g, int u, int v) { 
   g->mat[u][v] = g->mat[v][u] = 1;
}

void remover_grafo(Grafo* g, int u, int v) { 
   g->mat[u][v] = g->mat[v][u] = 0;
}

int n, a, b, componete[MAXN];
vector< int > aresta[MAXN];

void dfs(int n){
    for(int i = 0; i < n; i++){
        int v = aresta[0][i];
        if(componete[v] == 0){
            dfs(v);
        }
    }
}

int main() {
    Grafo *g = malloc(sizeof(Grafo));
    cria_grafo(g, 3);
    inserir_grafo(g, 1, 2);
    inserir_grafo(g, 0, 1);
    //remover_grafo(g, 0, 1);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%i ", g->mat[i][j]);
        }
        printf("\n");
    }

    printf("Ola");
    return 0;
}
