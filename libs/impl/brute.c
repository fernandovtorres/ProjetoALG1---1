#include "../brute.h"
#include <stdlib.h>
#include <string.h>
struct answer_ {
  int *path, minDistance, start;
};

void swap(int *n1, int *n2) {
  int temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

Answer *brute_force(Graph *graph, int start) {
  Answer *ans = malloc(sizeof(Answer));
  if (!ans) {
    return NULL;
  }
  ans->start = start;
  ans->path = malloc(sizeof(int) * getNumberOfVertices(graph));
  int *currPath = malloc(sizeof(int) * getNumberOfVertices(graph));
  for (int i = 0; i < getNumberOfVertices(graph); i++) {
    currPath[i] = i;
    if (i == start) {
      currPath[i] ^= currPath[0];
      currPath[0] ^= currPath[i];
      currPath[i] ^= currPath[0];
    }
  }
  ans->start = 1;
  bestPath(graph, &ans, currPath);
  return ans;
}

void bestPath(Graph *graph, Answer **ans, int *currPath) {
  if ((*ans)->start == getNumberOfVertices(graph) - 1) {
    int current_distance = totalDistance(graph, currPath);
    if (current_distance < (*ans)->minDistance) {
      (*ans)->minDistance = current_distance;
      memcpy((*ans)->path, currPath, getNumberOfVertices(graph) * sizeof(int));
    }
  } else {
    for (int i = (*ans)->start; i < getNumberOfVertices(graph); i++) {
      swap(&currPath[(*ans)->start], &currPath[i]);
      totalDistance(graph, currPath);
      swap(&currPath[(*ans)->start], &currPath[i]);
    }
  }
}

int totalDistance(Graph *graph, int *currPath) {
  int total = 0;
  for (int i = 0; i < getNumberOfVertices(graph) - 1; i++) {
    total += getWeightVertice(graph, currPath[i], currPath[i + 1]);
  }
  total += getWeightVertice(graph, currPath[getNumberOfVertices(graph)],
                            currPath[0]);
  return total;
}
