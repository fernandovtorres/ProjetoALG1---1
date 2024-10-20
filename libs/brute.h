#ifndef BRUTE_H
#define BRUTE_H
#include "deque.h"
#include "graph.h"
typedef struct answer_ Answer;
/*
 *  Inicia o algoritmo de força bruta
 *  começando com um caminho padrão: 1 - 2 - 3 - .. - n
 *  @param:
 *    Graph* graph: grafo, int start: cidade inicial
 *
 *  @return:
 *    Answer* answer: ponteiro para uma struct que contêm o caminho mais
 * otimizado e a distância mínima
 *
 * */
Answer *brute_force(Graph *graph, int start);

/*
 * Encontra o melhor caminho a partir da permutação das cidades e cálculo dos
 * caminhos gerados
 * @param:
 *  Graph* graph: grafo do problema
 *  Answer* ans: Struct que conterá a resposta para o problema
 *  Answer* auxAnswer: Struct auxiliar para avaliar os caminhos durante o
 * processo de resolução
 * DEQUE* aux: deque auxiliar utilizado para a permutação
 *  int start: inteiro representando a cidade de origem*/
static void bestPath(Graph *graph, Answer *ans, Answer *auxAnswer, DEQUE *aux,
                     int start);
/*
 * realiza um "print" da rota calculada
 * @param:
 *  Answer* ans: struct que guarda o caminho
 *  int start: inteiro que representa a cidade de inicio e consequentemente o
 * final
 *
 * @return:
 *  void*/
void path(Answer *ans, int start);
/* Retorna a distância mínima que foi calculada
 * @param:
 *  Answer* ans: struct que guarda a distância mínima
 *
 * @return:
 *  int distância: inteiro que representa a distância mínima calculada*/
int getMinDist(Answer *ans);
/*
 * Exclui o struct answer
 * @param:
 *  Answer **ans: endereço do struct ans
 *
 * @return:
 *  void*/
void deleteAnswer(Answer **ans);
#endif
