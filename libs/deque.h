#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>
#include <stdlib.h>
typedef struct deque_ DEQUE;
/*
 * Cria a Deque
 * @param:
 *  int size: tamanho da deque sequencial a ser criado
 *
 * @return:
 *  DEQUE*: ponteiro para a deque que foi criado*/
DEQUE *createDeque(int size);
/*
 * Apaga uma deque e libera a memória
 * @param:
 *  DEQUE** deque: endereço da deque que será apagada
 *
 * @return:
 *  void
 */
void deleteDeque(DEQUE **deque);
/*
 * Verifica se a deque está vazia
 * @param:
 *  DEQUE* deque: deque que será verificada
 *
 * @return:
 *  bool: resposta sobre a deque estar vazia*/
bool isEmptyDeque(DEQUE *deque);
/*
 * Verifica se a deque está cheia
 * @param:
 *  DEQUE* deque: deque que será verificada
 *
 * @return:
 *  bool: resposta sobre a deque estar cheia*/
bool isFullDeque(DEQUE *deque);
/*
 * Visualiza o elemento que está na frente(direita) da deque
 * @param:
 *  DEQUE* deque: deque que será verificada
 *
 * @return:
 *  int: o elemento que está na frente da deque*/
int dequeFront(DEQUE *deque);
/*
 * Visualiza o elemento que está na parte de trás(esquerda) da deque
 * @param:
 *  DEQUE* deque: deque que será verificada
 *
 * @return:
 *  int: o elemento que está na parte de trás da deque*/
int dequeBack(DEQUE *deque);
/*
 * Insere na frente(direita) da deque
 * @param:
 *  DEQUE* deque: deque na qual o elemento será inserido
 *  int value: valor que será inserido
 *
 * @return:
 *  bool: representa o sucesso da operação*/
bool dequeInsertFront(DEQUE *deque, int value);
/*
 * Insere na parte de trás(esquerda) da deque
 * @param:
 *  DEQUE* deque: deque na qual o elemento será inserido
 *  int value: valor que será inserido
 *
 * @return:
 *  bool: representa o sucesso da operação*/
bool dequeInsertBack(DEQUE *deque, int value);
/*
 * Remove da frente(direita) da deque
 * @param:
 *  DEQUE* deque: deque na qual o elemento será removido
 *
 * @return:
 *  bool: representa o sucesso da operação*/
int dequeRemoveFront(DEQUE *deque);
/*
 * Remove da parte de trás(esquerda) da deque
 * @param:
 *  DEQUE* deque: deque na qual o elemento será removido
 *
 * @return:
 *  bool: representa o sucesso da operação*/
int dequeRemoveBack(DEQUE *deque);
/*
 * Consulta o tamanho da deque
 * @param:
 *  DEQUE* deque: deque que será verificada
 *
 * @return:
 *  int: o tamanho da deque*/
int dequeSize(DEQUE *deque);
/*
 * Copia uma deque para outra
 * @param:
 *  DEQUE* src: deque que será copiada
 *  int size: tamanho da nova deque que será gerada*/
DEQUE *dequeCopy(DEQUE *src, int size);
/*
 * Printa a deque
 * @param:
 *  DEQUE* deque: deque que será usada para printar
 *
 * @return:
 *  void*/
void dequePrint(DEQUE *deque);
#endif
