#include "../brute.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct answer_ {
  int minDistance;
  DEQUE *caminho;
};

Answer *brute_force(Graph *graph, int start) {
  Answer *ans = malloc(sizeof(Answer));
  if (!ans) {
    return NULL;
  }
  ans->caminho = deque_criar(getNumberVertices(graph));
  ans->minDistance = INT_MAX;
  DEQUE *deque = deque_criar(getNumberVertices(graph));
  DEQUE *aux = deque_criar(getNumberVertices(graph));
  for (int i = 0; i < getNumberVertices(graph); i++) {
    deque_inserirFrente(aux, i + 1);
  } // O(n) sendo n o número de vértices
  bestPath(graph, &ans, deque, aux, start); // O(n!) -> (n-1)!
  deque_apagar(&deque);
  deque_apagar(&aux);
  return ans;
}

/* TODO: Começar a calcular o custo do caminho enquanto vai chamando a recursão
 * para que eu só precise comparar no final*/
static void bestPath(Graph *graph, Answer **ans, DEQUE *deque, DEQUE *aux,
                     int start) {
  if (deque_tamanho(aux) == 1) {
    deque_inserirFrente(deque, deque_removerAtras(aux));
    int current_distance = totalDistance(graph, deque, start); // O(n)
    if (current_distance < (*ans)->minDistance) {
      (*ans)->minDistance = current_distance;
      deque_apagar(&((*ans)->caminho));
      (*ans)->caminho = copiaDeque(deque, getNumberVertices(graph));
    }
    deque_inserirFrente(aux, deque_removerFrente(deque));
    return;
  } else {
    int tam = deque_tamanho(aux);
    for (int i = 0; i < tam; i++) {
      deque_inserirFrente(deque, deque_removerAtras(aux));
      bestPath(graph, ans, deque, aux, start);
      deque_inserirFrente(aux, deque_removerFrente(deque));
    }
  }
}

static int totalDistance(Graph *graph, DEQUE *deque, int start) {
  int total = 0;
  int *currPath = transferirArray(deque);
  if (currPath[0] != start) {
    free(currPath);
    currPath = NULL;
    return INT_MAX;
  }
  for (int i = 1; i < getNumberVertices(graph); i++) {
    int pesoAtual = getWeightEdge(graph, currPath[i - 1], currPath[i]);
    if (pesoAtual == INT_MAX) {
      free(currPath);
      currPath = NULL;
      return pesoAtual;
    }
    total += pesoAtual;
  }
  if (getWeightEdge(graph, currPath[getNumberVertices(graph) - 1],
                    currPath[0]) == INT_MAX) {
    free(currPath);
    currPath = NULL;
    return INT_MAX;
  }
  total +=
      getWeightEdge(graph, currPath[getNumberVertices(graph) - 1], currPath[0]);
  free(currPath);
  currPath = NULL;
  return total;
}

void path(Answer *ans) {
  if (ans) {
    dequePrintar(ans->caminho);
  }
  return;
}

int getMinDist(Answer *ans) {
  if (ans) {
    return ans->minDistance;
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
