#include "../graph.h"
#include <stdlib.h>

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
  vertice->edges = calloc(maxEdges, sizeof(int));
  return vertice;
}

static bool deleteVertice(Vertice **vertice) {
  if (*vertice) {
    free((*vertice)->edges);
    (*vertice)->edges = NULL;
    free(*vertice);
    *vertice = NULL;
    return true;
  }
  return false;
}

Graph *create_graph(int maxVertices, bool isDirected, bool isWeighted) {
  Graph *graph = malloc(sizeof(Graph));
  if (!graph) {
    return NULL;
  }
  graph->isDirected = isDirected;
  graph->isWeighted = isWeighted;
  graph->numberOfVertices = maxVertices;
  graph->graph = malloc(sizeof(Vertice *) * (maxVertices));
  for (int i = 0; i < maxVertices; i++) {
    Vertice *vertice = create_vertice(i, maxVertices);
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
  if (!graph) {
    return false;
  }
  vert1--;
  vert2--;
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
    return graph->graph[--vert1]->edges[--vert2];
  }
  exit(1);
}

void deleteGraph(Graph **graph, int maxVertices) {
  if (*graph) {
    for (int i = 0; i < maxVertices; i++) {
      deleteVertice(&((*graph)->graph[i]));
    }
    free((*graph)->graph);
    (*graph)->graph = NULL;
    free(*graph);
    *graph = NULL;
  }
}