#include "../deque.h"
#include <stdio.h>

struct deque_ {
  int *deque;
  int inicio, fim, qntItens, tamanho;
};

DEQUE *deque_criar(int tamanho) {
  DEQUE *deque = (DEQUE *)malloc(sizeof(DEQUE));
  if (!deque)
    return NULL;
  deque->deque = (int *)malloc(sizeof(int) * tamanho);
  if (!(deque->deque)) {
    free(deque);
    deque = NULL;
    return NULL;
  }
  deque->inicio = -1;
  deque->fim = deque->qntItens = 0;
  deque->tamanho = tamanho;
  return deque;
}

void deque_apagar(DEQUE **deque) {
  if (*deque) {
    free((*deque)->deque);
    (*deque)->deque = NULL;
    free(*deque);
    *deque = NULL;
  }
  return;
}

bool deque_vazia(DEQUE *deque) {
  if (!deque || deque->inicio == -1)
    return true;
  return false;
}

bool deque_cheia(DEQUE *deque) {
  if (!deque || deque->fim == deque->inicio)
    return true;
  return false;
}

int dequeFrente(DEQUE *deque) {
  if (!deque || deque_vazia(deque))
    exit(1);
  return deque->deque[(deque->fim - 1 + deque->tamanho) % deque->tamanho];
}
int dequeAtras(DEQUE *deque) {
  if (!deque || deque_vazia(deque))
    exit(1);
  return deque->deque[deque->inicio % deque->tamanho];
}

bool deque_inserirFrente(DEQUE *deque, int valor) {
  if (deque_cheia(deque))
    return false;
  if (deque->inicio == -1)
    deque->inicio = 0;
  deque->deque[deque->fim] = valor;
  deque->fim = (deque->fim + 1) % deque->tamanho;
  deque->qntItens += 1;
  return true;
}

bool deque_inserirAtras(DEQUE *deque, int valor) {
  if (deque_cheia(deque))
    return false;
  if (deque->inicio == -1) {
    deque->inicio = (deque->inicio + deque->tamanho) % deque->tamanho;
    deque->deque[deque->inicio] = valor;
  } else {
    deque->inicio = (deque->inicio - 1 + deque->tamanho) % deque->tamanho;
    deque->deque[deque->inicio] = valor;
  }
  deque->qntItens += 1;
  return true;
}

int deque_removerFrente(DEQUE *deque) {
  if (deque_vazia(deque))
    exit(1);
  deque->fim = (deque->fim - 1 + deque->tamanho) % deque->tamanho;
  int valor = deque->deque[deque->fim];
  if (deque->fim == deque->inicio) {
    deque->inicio = -1;
    deque->fim = 0;
  }
  deque->qntItens -= 1;
  return valor;
}

int deque_removerAtras(DEQUE *deque) {
  if (deque_vazia(deque))
    exit(1);
  int valor = deque->deque[deque->inicio % deque->tamanho];
  deque->inicio = (deque->inicio + 1) % deque->tamanho;
  if (deque->inicio == deque->fim) {
    deque->inicio = -1;
    deque->fim = 0;
  }
  deque->qntItens -= 1;
  return valor;
}

int deque_tamanho(DEQUE *deque) {
  if (deque)
    return deque->qntItens;
  exit(1);
}

DEQUE *copiaDeque(DEQUE *origem, int tamanho) {
  if (!origem) {
    return NULL;
  }

  DEQUE *temp = deque_criar(tamanho);
  DEQUE *novo = deque_criar(tamanho);
  while (!deque_vazia(origem)) {
    int item = deque_removerAtras(origem);
    deque_inserirFrente(novo, item);
    deque_inserirFrente(temp, item);
  }

  while (!deque_vazia(temp)) {
    int item = deque_removerAtras(temp);
    deque_inserirFrente(origem, item);
  }

  deque_apagar(&temp);

  return novo;
}

void dequePrintar(DEQUE *deque) {
  if (!deque)
    return;
  for (int i = deque->inicio;
       i != (deque->fim - 1 + deque->tamanho) % deque->tamanho;
       i = (i + 1) % deque->tamanho) {
    printf("%d - ", deque->deque[i]);
  }
  printf("%d - ",
         deque->deque[(deque->fim - 1 + deque->tamanho) % deque->tamanho]);
  return;
}
