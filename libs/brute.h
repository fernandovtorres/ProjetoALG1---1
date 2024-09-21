#ifndef BRUTE_H
#define BRUTE_H
#include "graph.h"
#include <stdlib.h>
typedef struct answer_ Answer;
Answer *brute_force(Graph *graph, int start);
void bestPath(Graph *graph, Answer **ans, int *currPath, int start);
int totalDistance(Graph *graph, int *currPath);
int path(Answer *ans, int index);
int getMinDist(Answer *ans);
void deleteAnswer(Answer **ans);
#endif