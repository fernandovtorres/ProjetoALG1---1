#include "../libs/branch.h"
#include "../libs/brute.h"
#include <limits.h>
#include <stdio.h>
#include <time.h>

int main(void) {
  int numberOfCities = 0, vert1 = 0, vert2 = 0, weight = 0, start = 0,
      edges = 0;
  clock_t inicio, fim;
  scanf(" %d", &numberOfCities);
  scanf(" %d", &start);
  scanf(" %d", &edges);
  Graph *graphh = createGraph(numberOfCities, 0, 1);
  for (int i = 0; i < edges; i++) {
    scanf(" %d %d %d", &vert1, &vert2, &weight);
    insertEdge(graphh, vert1, vert2, weight);
  }
  Graph *graph = cloneGraph(graphh);
  inicio = clock();
  Answer *ans = brute_force(graph, start);
  fim = clock();
  int minDist = getMinDist(ans);
  if (minDist == INT_MAX) {
    printf("Impossível!");
  } else {
    printf("Cidade Origem: %d\n", start);
    printf("Rota: ");
    for (int i = 0; i < numberOfCities; i++) {
      printf("%d - ", path(ans, i));
    }
    printf("%d\n", start);
    printf("Menor Distância: %d\n", minDist);
  }
  deleteGraph(&graph);
  deleteAnswer(&ans);
  return 0;
}
