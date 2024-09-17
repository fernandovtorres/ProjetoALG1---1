#ifndef BRUTE_H
#define BRUTE_H
#include "graph.h"
#include <stdlib.h>
typedef struct answer_ Answer;
Answer *brute_force(Graph *graph, int start);
void bestPath(Graph *graph, Answer **ans, int *currPath);
int totalDistance(Graph *graph, int *currPath);

#endif
