#ifndef VERTICE_H
#define VERTICE_H
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct vertice_ Vertice;
typedef struct edge_ Edge;
/*
 * Cria um vértice
 * @param:
 *  int size: tamanho máximo do vértice
 *  bool sorted: define se o vértice vai ter suas ligações ordenadas
 * @return:
 *  Vertice *: um ponteiro para o novo vertice*/
Vertice *createVertice(int size, bool sorted);
/*
 * Cria um array de vertices
 * @param:
 *  int vertices: quantidade de vertices no array
 *
 * @return:
 *  Vertice **: um array de vertices*/
Vertice **createVerticeList(int vertices);

static Edge createEdge(int index, int weight);
/*
 * Cria uma conexão (aresta) entre dois vértices
 * @param:
 *  Vertice *vert: vertice origem da conexão
 *  int index: index do vertice destino da conexão
 *  int weight: peso da aresta
 *
 * @return:
 *  bool: indica se a conexão foi feita com sucesso ou não*/
bool createConnection(Vertice *vert, int index, int weight);
/*
 * Recupera o peso de uma das conexões
 * @param:
 *  Vertice *vert: vertice origem da conexão
 *  int vert2: vertice destino da conexão
 *
 * @return:
 *  int: peso da aresta*/
int getWeightConnection(Vertice *vert, int vert2);

/*
 * Exclui um vertice
 * @param:
 *  Vertice **vertice: Endereço do vertice que será excluido
 *
 * @return:
 *  void*/
void deleteVertice(Vertice **vertice);
#endif
