#include "../brute.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct answer_ {
  int distance;
  DEQUE *path;
};

Answer *brute_force(Graph *graph, int start) {
  Answer *ans = (Answer *)malloc(sizeof(Answer));
  if (!ans) {
    return NULL;
  }
  Answer *auxAnswer = (Answer *)malloc(sizeof(Answer));
  if (!auxAnswer) {
    return NULL;
  }
  ans->path = createDeque(getNumberVertices(graph));
  ans->distance = INT_MAX; // define a distância como a máxima, definindo um
                           // estado inicial "infinito"
  auxAnswer->path = createDeque(getNumberVertices(graph));
  auxAnswer->distance = 0;
  DEQUE *aux = createDeque(getNumberVertices(graph));
  for (int i = 0; i < getNumberVertices(graph); i++) {
    if (i == start - 1)
      continue; // caso o indice da cidade seja igual ao da cidade de origem,
                // não insere ele na deque
    dequeInsertFront(aux, i + 1);
  }
  bestPath(graph, ans, auxAnswer, aux, start);
  deleteAnswer(&auxAnswer);
  deleteDeque(&aux);
  return ans;
}

static void bestPath(Graph *graph, Answer *ans, Answer *auxAnswer, DEQUE *aux,
                     int start) {
  int tamanho = dequeSize(aux);
  // Caso o tamanho do aux, seja 0, quer dizer que o caminho chegou ao final
  if (tamanho == 0) {
    int finalDistance =
        getWeightEdge(graph, dequeFront(auxAnswer->path), start);
    if (finalDistance == INT_MAX)
      return;
    auxAnswer->distance += finalDistance;
    // Atualiza a resposta final caso a distancia final no auxiliar seja menor
    // que a atual
    if (auxAnswer->distance < ans->distance) {
      ans->distance = auxAnswer->distance;
      deleteDeque(&(ans->path));
      ans->path = dequeCopy(auxAnswer->path, getNumberVertices(graph));
    }
    auxAnswer->distance -= finalDistance;
  } else {
    for (int i = 0; i < tamanho; i++) {
      int distancia = 0;
      // Calcula a distância da última cidade incluída no caminho com a próxima,
      // caso ainda não tenha nenhuma cidade, compara a primeira do auxiliar com
      // a cidade inicial
      if (!isEmptyDeque(auxAnswer->path)) {
        distancia =
            getWeightEdge(graph, dequeBack(aux), dequeFront(auxAnswer->path));
      } else {
        distancia = getWeightEdge(graph, dequeBack(aux), start);
      }
      if (distancia == INT_MAX) {
        dequeInsertFront(aux, dequeRemoveBack(aux));
        continue;
      }
      auxAnswer->distance += distancia;
      // Insere a cidade que teve a distancia calculada e chama a recursão para
      // continuar a permutação
      dequeInsertFront(auxAnswer->path, dequeRemoveBack(aux));
      bestPath(graph, ans, auxAnswer, aux, start);
      dequeInsertFront(aux, dequeRemoveFront(auxAnswer->path));
      auxAnswer->distance -= distancia;
    }
  }
  return;
}

void path(Answer *ans, int start) {
  if (ans) {
    printf("%d - ", start);
    dequePrint(ans->path);
    printf("%d\n", start);
  }
  return;
}

int getMinDist(Answer *ans) {
  if (ans) {
    return ans->distance;
  }
  exit(1);
}

void deleteAnswer(Answer **ans) {
  if (*ans) {
    deleteDeque(&((*ans)->path));
    free(*ans);
  }
  return;
}
