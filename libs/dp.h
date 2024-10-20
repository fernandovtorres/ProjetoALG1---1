#ifndef DP_H
#define DP_H
typedef struct dpAnswer_ DpAnswer;
/*
 * Inicia o algoritmo de programação dinamica construindo uma matriz dp para
 * calculo da distancia e uma matriz caminho para recuperar o caminho
 * @param:
 *  int **matrix: matriz do problema
 *  int start: cidade inicial
 *  int numberofCities: número de cidades do problema
 *
 * @return:
 *  DpAnswer*: um ponteiro para uma struct onde ficará guardado o caminho
 *  e as distâncias*/
DpAnswer *dp(int **matrix, int start, int numberofCities);
/*
 * Utiliza recursão para calcular a distância mínima para
 * cada conjunto de cidades e uma cidade específica. Para cada conjunto, testa
 * as cidades que não estão no conjunto. No final, retorna a menor distancia
 * global
 * @param:
 *  int bitmask: conjunto de cidades atual
 *  int actual: cidade atual da recursão
 *  int **matrix: matriz do problema
 *  int **dpMatrix: matriz onde se armazena os melhores globais
 *  int start: cidade que inicia o caminho
 *  int numberofCities: número de cidades
 *  int **pathMatrix: matriz onde se armazena a ultima cidade visitada no
 * caminho ótimo
 *
 * @return:
 *  int: distancia minima global*/

static int findDistance(int bitmask, int actual, int **matrix, int **dpMatrix,
                        int start, int numberofCities, int **pathMatrix);
/*
 * Utiliza a matriz que guarda os caminhos ótimos locais em conjunto da bitmask
 * para recuperar o caminho ótimo global
 * @param:
 *  int start: cidade inicial
 *  int **pathMatrix: matriz com os caminhos
 *  int numberofCities: número de cidades
 *
 * @return:
 *  int: contém a menor distância*/
static int *convertPath(int start, int **pathMatrix, int numberofCities);
/*
 * Realiza um print do caminho guardado na struct
 * @param:
 *  DpAnswer* ans: struct que contem o caminho
 *  int start: cidade inicial
 *  int size: tamanho do caminho
 *
 * @return:
 *  void*/
void printPath(DpAnswer *ans, int start, int size);
/*
 * Recupera a distância guardada dentro da struct
 * @param:
 *  DpAnswer* ans: struct que guarda a distância
 *
 * @return:
 *  int: distancia calculada*/
int getDistance(DpAnswer *ans);
/*
 * Exclui a struct que contem a resposta
 * @param:
 *  DpAnswer **dp: endereço da struct que contém a resposta
 *
 * @return:
 *  void*/
void deleteDpAnswer(DpAnswer **dp);
#endif
