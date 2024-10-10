#include "../deque.h"
#include <stdio.h>

struct deque_ {
  int *deque;
  int start, end, qntItems, size;
};

DEQUE *createDeque(int size) {
  DEQUE *deque = (DEQUE *)malloc(sizeof(DEQUE));
  if (!deque)
    return NULL;
  deque->deque = (int *)malloc(sizeof(int) * size);
  if (!(deque->deque)) {
    free(deque);
    deque = NULL;
    return NULL;
  }
  deque->start = -1;
  deque->end = deque->qntItems = 0;
  deque->size = size;
  return deque;
}

void deleteDeque(DEQUE **deque) {
  if (*deque) {
    free((*deque)->deque);
    (*deque)->deque = NULL;
    free(*deque);
    *deque = NULL;
  }
  return;
}

bool isEmptyDeque(DEQUE *deque) {
  if (!deque || deque->start == -1)
    return true;
  return false;
}

bool isFullDeque(DEQUE *deque) {
  if (!deque || deque->end == deque->start)
    return true;
  return false;
}

int dequeFront(DEQUE *deque) {
  if (!deque || isEmptyDeque(deque))
    exit(1);
  return deque->deque[(deque->end - 1 + deque->size) % deque->size];
}
int dequeBack(DEQUE *deque) {
  if (!deque || isEmptyDeque(deque))
    exit(1);
  return deque->deque[deque->start % deque->size];
}

bool dequeInsertFront(DEQUE *deque, int value) {
  if (isFullDeque(deque))
    return false;
  if (deque->start == -1)
    deque->start = 0;
  deque->deque[deque->end] = value;
  deque->end = (deque->end + 1) % deque->size;
  deque->qntItems += 1;
  return true;
}

bool dequeInsertBack(DEQUE *deque, int value) {
  if (isFullDeque(deque))
    return false;
  if (deque->start == -1) {
    deque->start = (deque->start + deque->size) % deque->size;
    deque->deque[deque->start] = value;
  } else {
    deque->start = (deque->start - 1 + deque->size) % deque->size;
    deque->deque[deque->start] = value;
  }
  deque->qntItems += 1;
  return true;
}

int dequeRemoveFront(DEQUE *deque) {
  if (isEmptyDeque(deque))
    exit(1);
  deque->end = (deque->end - 1 + deque->size) % deque->size;
  int valor = deque->deque[deque->end];
  if (deque->end == deque->start) {
    deque->start = -1;
    deque->end = 0;
  }
  deque->qntItems -= 1;
  return valor;
}

int dequeRemoveBack(DEQUE *deque) {
  if (isEmptyDeque(deque))
    exit(1);
  int valor = deque->deque[deque->start % deque->size];
  deque->start = (deque->start + 1) % deque->size;
  if (deque->start == deque->end) {
    deque->start = -1;
    deque->end = 0;
  }
  deque->qntItems -= 1;
  return valor;
}

int dequeSize(DEQUE *deque) {
  if (deque)
    return deque->qntItems;
  exit(1);
}

DEQUE *dequeCopy(DEQUE *src, int size) {
  if (!src) {
    return NULL;
  }

  DEQUE *temp = createDeque(size);
  DEQUE *clone = createDeque(size);
  while (!isEmptyDeque(src)) {
    int item = dequeRemoveBack(src);
    dequeInsertFront(clone, item);
    dequeInsertFront(temp, item);
  }

  while (!isEmptyDeque(temp)) {
    int item = dequeRemoveBack(temp);
    dequeInsertFront(src, item);
  }

  deleteDeque(&temp);

  return clone;
}

void dequePrint(DEQUE *deque) {
  if (!deque)
    return;
  for (int i = deque->start; i != (deque->end - 1 + deque->size) % deque->size;
       i = (i + 1) % deque->size) {
    printf("%d - ", deque->deque[i]);
  }
  printf("%d - ", deque->deque[(deque->end - 1 + deque->size) % deque->size]);
  return;
}
