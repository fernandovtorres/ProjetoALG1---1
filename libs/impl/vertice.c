#include "../vertice.h"
#include <limits.h>
#include <stdlib.h>

struct vertice_ {
  Edge *head;
};

struct edge_ {
  int index, weight;
  Edge *next;
};

Vertice **createVerticeList(int vertices) {
  Vertice **verticeList = (Vertice **)malloc(sizeof(Vertice *) * vertices);
  if (!verticeList) {
    return NULL;
  }
  return verticeList;
}

Vertice *createVertice(void) {
  Vertice *vertice = (Vertice *)malloc(sizeof(Vertice));
  if (!vertice) {
    return NULL;
  }
  vertice->head = NULL;
  return vertice;
}

static Edge *createEdge(int index, int weight) {
  Edge *edge = (Edge *)malloc(sizeof(Edge));
  if (!edge) {
    return NULL;
  }
  edge->index = index;
  edge->weight = weight;
  edge->next = NULL;
  return edge;
}

bool createConnection(Vertice *vert, int index, int weight) {
  Edge *edge = createEdge(index, weight);
  if (!edge) {
    return false;
  }
  if (vert->head == NULL) {
    vert->head = edge;
    return true;
  }
  Edge *dummy = vert->head;
  if (dummy->index > edge->index) {
    edge->next = dummy;
    vert->head = edge;
  } else if (dummy->index == edge->index) {
    dummy->weight = weight;
  } else {
    while (dummy->next != NULL) {
      if (dummy->next->index > edge->index) {
        break;
      } else if (dummy->next->index == edge->index) {
        dummy->next->weight = edge->weight;
        return true;
      }
      dummy = dummy->next;
    }

    edge->next = dummy->next;
    dummy->next = edge;
  }
  return true;
}

int getWeightConnection(Vertice *vert, int vert2) {
  int weight = INT_MAX;
  Edge *dummy = vert->head;
  while (dummy && dummy->index <= vert2) {
    if (dummy->index == vert2) {
      weight = dummy->weight;
      break;
    }
    dummy = dummy->next;
  }
  return weight;
}

static void deleteEdge(Edge **edge) {
  if (*edge) {
    free(*edge);
    *edge = NULL;
  }
  return;
}

void deleteVertice(Vertice **vertice) {
  if (*vertice) {
    while ((*vertice)->head) {
      Edge *dummy = (*vertice)->head;
      (*vertice)->head = (*vertice)->head->next;
      deleteEdge(&dummy);
    }
    free(*vertice);
    *vertice = NULL;
  }
  return;
}
