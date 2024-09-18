#include "../brute.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>
struct answer_ {
  int *path, minDistance;
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
  ans->path = malloc(sizeof(int) * (getNumberOfVertices(graph) + 1));
  ans->minDistance = INT_MAX;
  int *currPath = malloc(sizeof(int) * (getNumberOfVertices(graph) + 1));
  for (int i = 1; i < getNumberOfVertices(graph) + 1; i++) {
    currPath[i] = i;
    if (i == start) {
      currPath[i] ^= currPath[1];
      currPath[1] ^= currPath[i];
      currPath[i] ^= currPath[1];
    }
  }
  bestPath(graph, &ans, currPath, 2);
  return ans;
}

void bestPath(Graph *graph, Answer **ans, int *currPath, int start) {
  if (start >= getNumberOfVertices(graph)) {
    int current_distance = totalDistance(graph, currPath);
    if (current_distance < (*ans)->minDistance) {
      (*ans)->minDistance = current_distance;
      memcpy((*ans)->path, currPath, getNumberOfVertices(graph) * sizeof(int));
    }
  } else {
    for (int i = start; i < getNumberOfVertices(graph); i++) {
      swap(&currPath[start], &currPath[i]);
      bestPath(graph, ans, currPath, start + 1);
      swap(&currPath[start], &currPath[i]);
    }
  }
}

int totalDistance(Graph *graph, int *currPath) {
  int total = 0;
  for (int i = 2; i < getNumberOfVertices(graph) + 1; i++) {
    total += getWeightVertice(graph, currPath[i - 1], currPath[i]);
  }
  total += getWeightVertice(graph, currPath[getNumberOfVertices(graph)],
                            currPath[1]);
  return total;
}

int path(Answer *ans, int index) {
  if (ans) {
    return ans->path[index];
  }
  exit(1);
}

int getMinDist(Answer *ans) {
  if (ans) {
    return ans->minDistance;
  }
  exit(1);
}

void deleteAnswer(Answer **ans) {
  if (*ans) {
    free((*ans)->path);
    free(*ans);
  }
  return;
}
