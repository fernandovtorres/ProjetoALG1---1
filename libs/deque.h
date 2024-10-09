#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>
#include <stdlib.h>
typedef struct deque_ DEQUE;
/*
 * Cria a Deque
 * @param:
 *  int tamanho: tamanho da deque sequencial a ser criado
 *
 * @return:
 *  DEQUE*: ponteiro para a deque que foi criado*/
DEQUE *deque_criar(int tamanho);
/*
 * Apaga uma deque e libera a memória
 * @param:
 *  DEQUE** deque: endereço da deque que será apagada
 *
 * @return:
 *  void
 */
void deque_apagar(DEQUE **deque);
/*
 * Verifica se a deque está vazia
 * @param:
 *  DEQUE* deque: deque que será verificada
 *
 * @return:
 *  bool: resposta sobre a deque estar vazia*/
bool deque_vazia(DEQUE *deque);
/*
 * Verifica se a deque está cheia
 * @param:
 *  DEQUE* deque: deque que será verificada
 *
 * @return:
 *  bool: resposta sobre a deque estar cheia*/
bool deque_cheia(DEQUE *deque);
/*
 * Visualiza o elemento que está na frente(direita) da deque
 * @param:
 *  DEQUE* deque: deque que será verificada
 *
 * @return:
 *  */
int dequeFrente(DEQUE *deque);
int dequeAtras(DEQUE *deque);
bool deque_inserirFrente(DEQUE *deque, int valor);
bool deque_inserirAtras(DEQUE *deque, int valor);
int deque_removerFrente(DEQUE *deque);
int deque_removerAtras(DEQUE *deque);
int deque_tamanho(DEQUE *deque);
DEQUE *copiaDeque(DEQUE *origem, int tamanho);
void dequePrintar(DEQUE *deque);
#endif
