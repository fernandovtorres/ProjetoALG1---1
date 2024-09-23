#ifndef GRAPH_H
#define GRAPH_H
#include <stdbool.h>
typedef struct graph_ Graph;
typedef struct vertice_ Vertice;
static Vertice *create_vertice(int value, int maxEdges);
static bool deleteVertice(Vertice **vertice);
/*
 * Cria um gráfico passando algumas configurações
 * @param:
 *  int maxVertices: quantidade máxima de vértices no gráfico
 *  bool isDirected: Define se o gŕafico é direcionado
 *  bool isWeighted: Define se o gráfico contém pesos
 *
 * @return:
 *  Graph *: ponteiro para o gŕafico criado*/
Graph *create_graph(int maxVertices, bool isDirected, bool isWeighted);
/*
 * Retorna o número de vértices do gráfico
 * @param:
 *  Graph* graph: grafo que contém o número de vértices
 *
 * @return:
 *  int vertices: inteiro que representa o número máximo de vértices*/
int getNumberOfVertices(Graph *graph);
/*
 * Insere uma aresta no grafo
 * @param:
 *  Graph *graph: grafo onde será inserido a aresta
 *  int vert1: primeiro vértice
 *  int vert2: segundo vértice
 *  int weight: caso o grafo tenha peso, inseri o peso na aresta
 *
 * @return:
 *  bool sucess: bool representando o sucesso da operação*/
bool insertEdge(Graph *graph, int vert1, int vert2, int weight);
/*
 * Retorna o peso de uma aresta
 * @param:
 *  Graph *graph: grafo
 *  int vert1: vert1 da conexão
 *  int vert2: vert2 da conexão*/
int getWeightEdge(Graph *graph, int vert1, int vert2);
/*
 * Exclui e da free no gráfico
 * @param:
 *  Graph **graph: endereço do grafo a ser excluído
 *  int maxVertices: vertices a serem excluídos
 *
 * @return:
 *  sem retornar*/
void deleteGraph(Graph **graph, int maxVertices);
#endif
