#include "../vertice.h"
#include <limits.h>
#include <stdlib.h>
struct vertice_ {
  Edge *edges;
  int start, end, size;
  bool ordenada;
};

struct edge_ {
  int index, weight;
};

Vertice *createVertice(int tamanho, bool ordenada) {
  Vertice *vertice = (Vertice *)malloc(sizeof(Vertice));
  if (!vertice)
    return NULL;
  vertice->edges = (Edge *)malloc(sizeof(Edge) * tamanho);
  if (!(vertice->edges)) {
    free(vertice);
    vertice = NULL;
    return NULL;
  }
  vertice->start = vertice->end = 0;
  vertice->size = tamanho;
  vertice->ordenada = ordenada;
  return vertice;
}

Vertice **createVerticeList(int vertices) {
  Vertice **verticeList = (Vertice **)malloc(sizeof(Vertice *) * vertices);
  if (!verticeList)
    return NULL;
  return verticeList;
}

static Edge createEdge(int index, int weight) {
  Edge edge;
  edge.index = index;
  edge.weight = weight;
  return edge;
}

bool createConnection(Vertice *vert, int index, int weight) {
  if (vert->end == vert->size)
    return false;
  Edge edge = createEdge(index, weight);
  if (vert->start != vert->end) {
    int left = vert->start;
    int right = vert->end;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (vert->edges[mid].index < index)
        right = mid - 1;
      else if (vert->edges[mid].index > index)
        left = mid + 1;
      else {
        vert->edges[mid] = edge;
        return true;
      }
    }
    for (int i = vert->end - 1; i >= left; i--) {
      vert->edges[i + 1] = vert->edges[i];
    }
    vert->edges[left] = edge;
  } else {
    vert->edges[vert->end] = edge;
  }
  vert->end++;
  return true;
}

int getWeightConnection(Vertice *vert, int vert2) {
  if (!vert || vert->start == vert->end)
    return INT_MAX;
  int left = vert->start;
  int right = vert->end;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (vert->edges[mid].index < vert2)
      right = mid - 1;
    else if (vert->edges[mid].index > vert2)
      left = mid + 1;
    else {
      return vert->edges[mid].weight;
    }
  }
  return INT_MAX;
}

void deleteVertice(Vertice **vertice) {
  if (*vertice) {
    free((*vertice)->edges);
    (*vertice)->edges = NULL;
    free(*vertice);
    *vertice = NULL;
  }
  return;
}
