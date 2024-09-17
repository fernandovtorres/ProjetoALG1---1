#include "../graph.h"
#include <stdlib.h>
// WARNING: Turn the edges array in a "true" list
struct graph_ {
  Vertice **graph;
  int numberOfVertices;
  bool isDirected, isWeighted;
};

struct vertice_ {
  int value;
  int *edges;
};

static Vertice *create_vertice(int value, int maxEdges) {
  Vertice *vertice = malloc(sizeof(Vertice));
  if (!vertice) {
    return NULL;
  }
  vertice->value = value;
  vertice->edges = malloc(sizeof(int) * maxEdges);
  return vertice;
}

Graph *create_graph(int maxVertices, bool isDirected, bool isWeighted) {
  Graph *graph = malloc(sizeof(Graph));
  if (!graph) {
    return NULL;
  }
  graph->isDirected = isDirected;
  graph->isWeighted = isWeighted;
  graph->numberOfVertices = maxVertices;
  graph->graph = malloc(sizeof(Vertice *) * maxVertices);
  for (int i = 0; i < maxVertices; i++) {
    Vertice *vertice = create_vertice(i, maxVertices - 1);
    if (!vertice) {
      return NULL;
    }
    graph->graph[vertice->value] = vertice;
  }
  return graph;
}

int getNumberOfVertices(Graph *graph) {
  if (graph) {
    return graph->numberOfVertices;
  }
  exit(1);
}

bool insertEdge(Graph *graph, int vert1, int vert2, int weight) {
  if (!graph || !vert1 || !vert2) {
    return false;
  }
  if (!graph->isDirected) {
    if (graph->isWeighted) {
      (graph->graph[vert1])->edges[vert2] = weight;
      (graph->graph[vert2])->edges[vert1] = weight;
    } else {
      (graph->graph[vert1])->edges[vert2] = 1;
      (graph->graph[vert2])->edges[vert1] = 1;
    }
  } else {
    if (graph->isWeighted) {
      (graph->graph[vert1])->edges[vert2] = weight;
    } else {
      (graph->graph[vert1])->edges[vert2] = 1;
    }
  }
  return true;
}

int getWeightVertice(Graph *graph, int vert1, int vert2) {
  if (graph) {
    return graph->graph[vert1]->edges[vert2];
  }
  exit(1);
}
