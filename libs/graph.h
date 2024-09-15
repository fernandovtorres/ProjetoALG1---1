#ifndef GRAPH_H
#define GRAPH_H
#include "vertice.h"
#include <stdbool.h>
typedef struct graph_ Graph;
Graph *create_graph(int maxVertices, bool isDirected, bool isWeighted);
int numberOfVertices(Graph *graph);
bool insertEdge(Vertice *vert1, Vertice *vert2, int weight);
#endif
