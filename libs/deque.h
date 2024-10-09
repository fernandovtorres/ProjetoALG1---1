#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>
#include <stdlib.h>
typedef struct deque_ DEQUE;
DEQUE *deque_criar(int tamanho);
void deque_apagar(DEQUE **deque);
bool deque_vazia(DEQUE *deque);
bool deque_cheia(DEQUE *deque);
int dequeFrente(DEQUE *deque);
int dequeAtras(DEQUE *deque);
bool deque_inserirFrente(DEQUE *deque, int valor);
bool deque_inserirAtras(DEQUE *deque, int valor);
int deque_removerFrente(DEQUE *deque);
int deque_removerAtras(DEQUE *deque);
int deque_tamanho(DEQUE *deque);
DEQUE *copiaDeque(DEQUE *origem, int tamanho);
void dequePrintar(DEQUE *deque);
int *transferirArray(DEQUE *deque);
#endif
