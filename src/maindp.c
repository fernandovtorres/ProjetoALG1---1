#include "../libs/dp.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int numberOfCities = 0, vert1 = 0, vert2 = 0, weight = 0, start = 0,
      edges = 0;
  scanf(" %d", &numberOfCities);
  scanf(" %d", &start);
  scanf(" %d", &edges);

  int **matrix = (int **)malloc(numberOfCities * sizeof(int *));
  for (int i = 0; i < numberOfCities; i++) {
    matrix[i] = (int *)malloc(numberOfCities * sizeof(int));
    for (int j = 0; j < numberOfCities; j++) {
      if (i == j)
        matrix[i][j] = 0;
      else
        matrix[i][j] = INT_MAX;
    }
  } // Crio a matriz e defino a distância entre as cidades como infinita

  for (int i = 0; i < edges; i++) {
    scanf(" %d", &vert1);
    vert1--;
    scanf(" %d", &vert2);
    vert2--;
    scanf(" %d", &weight);
    matrix[vert1][vert2] = weight;
    matrix[vert2][vert1] = weight;
  } // Coloco as reais distâncias na matriz
  DpAnswer *ans =
      dp(matrix, start, numberOfCities); // chamada da função para calcular
  printf("Cidade Origem: %d\n", start);
  printf("Rota: ");
  printPath(ans, start, numberOfCities);
  printf("Menor Distância: %d\n", getDistance(ans));
  deleteDpAnswer(&ans);
  for (int i = 0; i < numberOfCities; i++) {
    free(matrix[i]);
    matrix[i] = NULL;
  }
  free(matrix);
  matrix = NULL;
  return 0;
}
