#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

struct graph {

    int vertices; // Quantidade de vertices
    int edges; // Quantidade de arestras
    int ** matrix; // Matriz de adjacencia

};

Graph * create_graph (int dimension) {

    Graph * adj = (Graph *) malloc(sizeof(Graph));

    if (adj) {

        adj->vertices = dimension;
        adj->edges = 0;
        
        // Cria matriz
        adj->matrix = (int **) (malloc(dimension * sizeof(int *)));

        for (int i = 0; i < dimension; i++) adj->matrix[i] = (int *) (malloc(dimension * sizeof(int)));

        // Atribui valores
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                adj->matrix[i][j] = 0;
            }
        }
    }

    return adj;
}

void insert_edge_graph (Graph * adj, int i, int j) {

    // Verifica se o arco em questao ja existe
    if (adj->matrix[i][j] == 0) {
        adj->matrix[i][j] = 1;
        adj->edges++;
    }
}

void remove_edge_graph (Graph * adj, int i, int j) {

    // Verifica se o arco em questao ja existe
    if (adj->matrix[i][j] == 1) {
        adj->matrix[i][j] = 0;
        adj->edges--;
    }
}

// Funcao que retorna peso de determinada aresta do vertice
int get_edge_graph (Graph * adj, int i, int j, int * weight) {

    if (adj)  {
        * weight = adj->matrix[i][j];
        return 1;
    }

    return 0;
}

// Funcao que exibe a amtriz
void print_graph (Graph * adj) {

    for (int i = 0; i < adj->vertices; i++) {
        for (int j = 0; j < adj->vertices; j++) {
            printf("%d ", adj->matrix[i][j]);        
        }
        printf("\n");
    }
}

// Funcao que libera grafo
void free_graph (Graph * adj) {

    for (int i = 0; i < adj->vertices; i++) free(adj->matrix[i]);

    free(adj->matrix);
    free(adj);
}
