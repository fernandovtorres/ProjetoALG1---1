#include "../libs/branch.h"
#include "../libs/brute.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

int pa(double n) { return ceil((n * (n + 1)) / 2); }

int main(void) {
  int numberOfCities = 0, vert1 = 0, vert2 = 0, weight = 0, start = 0,
      edges = 0;
  scanf(" %d", &numberOfCities);
  scanf(" %d", &start);
  scanf(" %d", &edges);
  Graph *graph = create_graph(numberOfCities, 0, 1);
  for (int i = 0; i < edges; i++) {
    scanf(" %d %d %d", &vert1, &vert2, &weight);
    insertEdge(graph, vert1, vert2, weight);
  }
  Answer *ans = brute_force(graph, start);
  int minDist = getMinDist(ans);
  if (minDist == INT_MAX) {
    printf("Impossível!\n");
  } else {
    printf("Cidade Origem: %d\n", start);
    printf("Rota: ");
    for (int i = 0; i < numberOfCities; i++) {
      printf("%d - ", path(ans, i));
    }
    printf("%d\n", start);
    printf("Menor Distância: %d\n", minDist);
  }
  deleteGraph(&graph, numberOfCities);
  deleteAnswer(&ans);
  return 0;
}
