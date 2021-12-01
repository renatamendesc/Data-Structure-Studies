#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph Graph;

Graph * create_graph (int dimension);

void insert_edge_graph (Graph * adj, int i, int j);
void remove_edge_graph (Graph * adj, int i, int j);
int get_edge_graph (Graph * adj, int i, int j, int * weight);
void print_graph (Graph * adj);
void free_graph (Graph * adj);

#endif