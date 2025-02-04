#include "../libs/brute.h"
#include <limits.h>
#include <stdio.h>
/*  Integrantes:
 *    Fernando Valentim Torres - 15452340
 *    Artur Kenzo Obara Kawazoe - 15652663
 *    Daniel Jorge Manzano - 15446861
 */

int main(void) {
  int numberOfCities = 0, vert1 = 0, vert2 = 0, weight = 0, start = 0,
      edges = 0;
  scanf(" %d", &numberOfCities);
  scanf(" %d", &start);
  scanf(" %d", &edges);
  Graph *graph = createGraph(numberOfCities, 0, 1);
  for (int i = 0; i < edges; i++) {
    scanf(" %d %d %d", &vert1, &vert2, &weight);
    insertEdge(graph, vert1, vert2, weight);
  }
  Answer *ans = brute_force(graph, start);
  int minDist = getMinDist(ans);
  if (minDist == INT_MAX) {
    printf("Impossível!");
  } else {
    printf("Cidade Origem: %d\n", start);
    printf("Rota: ");
    path(ans, start);
    printf("Menor Distância: %d\n", minDist);
  }
  deleteGraph(&graph);
  deleteAnswer(&ans);
  return 0;
}
