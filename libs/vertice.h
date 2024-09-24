#ifndef VERTICE_H
#define VERTICE_H
#include <stdbool.h>
typedef struct vertice_ Vertice;
typedef struct edge_ Edge;
Vertice *createVertice(int maxConnections);
Vertice **createVerticeList(int vertices);
static Edge *createEdge(int index, int weight);
bool createConnection(Vertice *vert, int index, int weight);
int getWeightConnection(Vertice *vert, int vert2);
static void deleteEdge(Edge **edge);
void deleteVertice(Vertice **vertice);
#endif
