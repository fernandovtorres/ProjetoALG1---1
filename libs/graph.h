#ifndef GRAPH_H
#define GRAPH_H
#include "vertice.h"
typedef struct graph_ Graph;
Graph *createGraph(int vertices, bool isDirected, bool isWeighted);
bool insertEdge(Graph *graph, int vertice1, int vertice2, int weight);
int getWeightEdge(Graph *graph, int vertice1, int vertice2);
int getNumberVertices(Graph *graph);
void deleteGraph(Graph **graph);
#endif
