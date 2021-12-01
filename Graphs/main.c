#include "graph.h"
#include <stdio.h>

int main (void) {

    int dimension = 9; // Quantidade total de vertices

    Graph * adj = create_graph(dimension);

    // Vertices ligados a A
    insert_edge_graph(adj, 0, 1);
    insert_edge_graph(adj, 0, 2);
    insert_edge_graph(adj, 0, 3);
    insert_edge_graph(adj, 0, 5);

    // Vertices ligados a B
    insert_edge_graph(adj, 1, 0);
    insert_edge_graph(adj, 1, 5);
    insert_edge_graph(adj, 1, 2);
    insert_edge_graph(adj, 1, 7);

    // Vertices ligados a C
    insert_edge_graph(adj, 2, 1);
    insert_edge_graph(adj, 2, 5);
    insert_edge_graph(adj, 2, 0);

    // Vertices ligados a D
    insert_edge_graph(adj, 3, 0);
    insert_edge_graph(adj, 3, 4);
    insert_edge_graph(adj, 3, 6);

    // Vertices ligados a E
    insert_edge_graph(adj, 4, 5);
    insert_edge_graph(adj, 4, 3);

    // Vertices ligados a F
    insert_edge_graph(adj, 5, 0);
    insert_edge_graph(adj, 5, 1);
    insert_edge_graph(adj, 5, 2);
    insert_edge_graph(adj, 5, 6);
    insert_edge_graph(adj, 5, 4);

    // Vertices ligados a G
    insert_edge_graph(adj, 6, 3);
    insert_edge_graph(adj, 6, 5);
    insert_edge_graph(adj, 6, 8);

    // Vertices ligados a H
    insert_edge_graph(adj, 7, 1);
    insert_edge_graph(adj, 7, 8);

    // Vertices ligados a I
    insert_edge_graph(adj, 8, 7);
    insert_edge_graph(adj, 8, 6);

    print_graph(adj); // Exibe matriz de adjacencia

    free_graph(adj); // Libera o grafo

    return 0;
}