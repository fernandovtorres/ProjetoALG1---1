#include "../dp.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct dpAnswer_ {
  int distance;
  int *path;
};

DpAnswer *dp(int **matrix, int start, int numberofCities) {
  start--;
  DpAnswer *dp = (DpAnswer *)malloc(sizeof(DpAnswer));
  if (!dp)
    return NULL;

  int **dpMatrix = (int **)malloc((1 << numberofCities) * sizeof(int *));

  int **pathMatrix = (int **)malloc((1 << numberofCities) * sizeof(int *));

  for (int i = 0; i < (1 << numberofCities); i++) {
    dpMatrix[i] = (int *)malloc(sizeof(int) * numberofCities);

    pathMatrix[i] = (int *)malloc(sizeof(int) * numberofCities);

    for (int j = 0; j < numberofCities; j++) {
      dpMatrix[i][j] = pathMatrix[i][j] = -1;
    }
  } // Crio a matriz para a dp e para o caminho

  dp->distance = findDistance(1 << start, start, matrix, dpMatrix, start,
                              numberofCities, pathMatrix);

  dp->path = convertPath(start, pathMatrix, numberofCities);

  for (int i = 0; i < (1 << numberofCities); i++) {
    free(dpMatrix[i]);
    dpMatrix[i] = NULL;
    free(pathMatrix[i]);
    pathMatrix[i] = NULL;
  }

  free(dpMatrix);
  dpMatrix = NULL;

  free(pathMatrix);
  pathMatrix = NULL;
  return dp;
}

static int findDistance(int bitmask, int actual, int **matrix, int **dpMatrix,
                        int start, int numberofCities, int **pathMatrix) {
  if (bitmask == (1 << numberofCities) - 1) {
    if (matrix[actual][start] == 0)
      return dpMatrix[bitmask][actual] = INT_MAX;
    dpMatrix[bitmask][actual] = matrix[actual][start];
    return dpMatrix[bitmask][actual];
  }

  if (dpMatrix[bitmask][actual] != -1) // retorno caso a já tenha sido calculado
    return dpMatrix[bitmask][actual];

  int actualDistance = INT_MAX;

  for (int i = 0; i < numberofCities; i++) {
    // Pulo a iteração caso não exista rota ou
    // a cidade já tenha sido visitada
    if (bitmask & (1 << i) || matrix[actual][i] == INT_MAX)
      continue;

    int auxDistance = findDistance((bitmask | (1 << i)), i, matrix, dpMatrix,
                                   start, numberofCities, pathMatrix);
    // Atualizo a distância caso minha distância
    // auxiliar tenha encontrado uma rota (!= INT_MAX) e ela
    // seja menor que o meu global atual
    if (actualDistance > auxDistance + matrix[actual][i] &&
        auxDistance != INT_MAX) {
      actualDistance = auxDistance + matrix[actual][i];
      pathMatrix[bitmask][actual] = i;
    }
  }
  return dpMatrix[bitmask][actual] = actualDistance;
}

static int *convertPath(int start, int **pathMatrix, int numberofCities) {
  int *path = (int *)calloc((numberofCities - 1), sizeof(int));
  int position = start, bitmask = 1 << start;
  for (int i = 0; i < numberofCities - 1; i++) {
    /* Reconstrói o caminho utilizando a bitmask e a matriz pai */
    position = pathMatrix[bitmask][position];
    path[i] = position + 1;
    bitmask = bitmask | (1 << position);
  }
  return path;
}

void printPath(DpAnswer *ans, int start, int size) {
  printf("%d - ", start);
  for (int i = 0; i < size - 1; i++) {
    printf("%d - ", ans->path[i]);
  }
  printf("%d\n", start);
}

int getDistance(DpAnswer *ans) {
  if (ans)
    return ans->distance;
  exit(1);
}

void deleteDpAnswer(DpAnswer **dp) {
  if (*dp) {
    free((*dp)->path);
    (*dp)->path = NULL;
    free(*dp);
    *dp = NULL;
  }
  return;
}
