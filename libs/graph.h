#ifndef GRAPH_H
#define GRAPH_H
#include <stdbool.h>
typedef struct graph_ Graph;
typedef struct vertice_ Vertice;
static Vertice *create_vertice(int value, int maxEdges);
static bool deleteVertice(Vertice **vertice);
Graph *create_graph(int maxVertices, bool isDirected, bool isWeighted);
int getNumberOfVertices(Graph *graph);
bool insertEdge(Graph *graph, int vert1, int vert2, int weight);
int getWeightVertice(Graph *graph, int vert1, int vert2);
void deleteGraph(Graph **graph, int maxVertices);
#endif
