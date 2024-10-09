#include "../brute.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct answer_ {
  int distance;
  DEQUE *caminho;
};

Answer *brute_force(Graph *graph, int start) {
  Answer *ans = malloc(sizeof(Answer));
  if (!ans) {
    return NULL;
  }
  Answer *auxAnswer = malloc(sizeof(Answer));
  if (!auxAnswer) {
    return NULL;
  }
  ans->caminho = deque_criar(getNumberVertices(graph));
  ans->distance = INT_MAX;
  auxAnswer->caminho = deque_criar(getNumberVertices(graph));
  auxAnswer->distance = 0;
  DEQUE *aux = deque_criar(getNumberVertices(graph));
  for (int i = 0; i < getNumberVertices(graph); i++) {
    if (i == start - 1)
      continue;
    deque_inserirFrente(aux, i + 1);
  } // O(n) sendo n o número de vértices
  bestPath(graph, ans, auxAnswer, aux, start); // O(n!) -> (n-1)!
  deleteAnswer(&auxAnswer);
  deque_apagar(&aux);
  return ans;
}

static void bestPath(Graph *graph, Answer *ans, Answer *auxAnswer, DEQUE *aux,
                     int start) {
  int tamanho = deque_tamanho(aux);
  if (tamanho == 0) {
    int finalDistance =
        getWeightEdge(graph, dequeFrente(auxAnswer->caminho), start);
    if (finalDistance == INT_MAX)
      return;
    auxAnswer->distance += finalDistance;
    if (auxAnswer->distance < ans->distance) {
      ans->distance = auxAnswer->distance;
      deque_apagar(&(ans->caminho));
      ans->caminho = copiaDeque(auxAnswer->caminho, getNumberVertices(graph));
    }
    auxAnswer->distance -= finalDistance;
  } else {
    for (int i = 0; i < tamanho; i++) {
      int distancia = 0;
      if (!deque_vazia(auxAnswer->caminho)) {
        distancia = getWeightEdge(graph, dequeAtras(aux),
                                  dequeFrente(auxAnswer->caminho));
      } else {
        distancia = getWeightEdge(graph, dequeAtras(aux), start);
      }
      if (distancia == INT_MAX) {
        deque_inserirFrente(aux, deque_removerAtras(aux));
        continue;
      }
      auxAnswer->distance += distancia;
      deque_inserirFrente(auxAnswer->caminho, deque_removerAtras(aux));
      bestPath(graph, ans, auxAnswer, aux, start);
      deque_inserirFrente(aux, deque_removerFrente(auxAnswer->caminho));
      auxAnswer->distance -= distancia;
    }
  }
  return;
}

void path(Answer *ans, int start) {
  if (ans) {
    printf("%d - ", start);
    dequePrintar(ans->caminho);
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
    deque_apagar(&((*ans)->caminho));
    free(*ans);
  }
  return;
}
