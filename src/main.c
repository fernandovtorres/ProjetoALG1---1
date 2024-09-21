#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "libs/brute.h"
#include "libs/graph.h"

//tentativa de fazer um algoritmo "otimizado" pra solucionar o problema do caixeiro viajante (nao vai ser otimizado nao, mas é pra ser menos pior que o força bruta) 

int pa(double n){
    return ceil((n * (n + 1)) / 2); 
}

int distanciamin(Graph *graph, int numcidades){ //aqui vou calcular a distancia minima que duas cidades podem ter
    int aux = 0, soma = 0; //o auxiliar vai pegar o menor valor da linha/coluna . a soma vou usar pra achar essa distancia minima aí

    for(int i = 0; i < numcidades; i++){
        aux = getWeightVertice(graph, i, 0); //pego ja o primeiro numero da "matriz" pra comparar dps
        for(int j = 1; j < numcidades; j++){ //aq começo no 1 pq ja tenho o valor do 0 da linha de cima
            if(aux > getWeightVertice(graph, i, j)) aux = getWeightVertice(graph, i, j); //procuro um valor menor na linha
        } //saindo daqui eu tenho o menor valor da linha
        if(!aux) break; //se o menor valor na linha é 0 nao vou fazer nenhuma alteração na frente, entao dá break
        soma += aux; //a soma basicamente armazena a soma dos menores valores das linhas e colunas
        for(int j = 0; j < numcidades; j++){ //percorro a mesma linha pra mexer aq
            insertEdge(graph, i, j, getWeightVertice(graph, i, j) - aux); //subtraio o menor valor da linha em geral dali
        }
    }

    for(int i = 0; i < numcidades; i++){ //mesma logica de cima, só muda que to mexendo com coluna e nao linha
        aux = getWeightVertice(graph, 0, i); 
        for(int j = 1; j < numcidades; j++){ 
            if(aux > getWeightVertice(graph, j, i)) aux = getWeightVertice(graph, j, i); 
        } 
        if(!aux) break;
        soma += aux;
        for(int j = 0; j < numcidades; j++){ 
            insertEdge(graph, j, i, getWeightVertice(graph, j, i) - aux); 
        }
    }//dps disso tudo tenho teoricamente uma "matriz reduzida" e a soma de todos os minimos que achei no caminho
    
    return soma;
}

Graph *diagonal(Graph *graph, int numcidades){ //so coloca a diagonal principal com o tamanho maximo
    for(int i = 0; i < numcidades; i++){
        insertEdge(graph, i, i, INT_MAX);
    }
}

//aqui tanho que fazer uma funçao que calula as distancia e acha a melhor opcao de cidade seguinte (to pensando em fazer algo recursivo talvez...)

Answer *tsp(Graph *graph, int numcidades){
    graph = diagonal(graph, numcidades); //arrumo a diagonal principal pra ter um tamanho grandao (preciso disso no algoritmo)
    int distmin = distanciamin(graph, numcidades);


}

int main(void){

    int numcidades = 0, vert1 = 0, vert2 = 0, peso = 0, comeco = 0; //peguei do codigo do fernando. só pra pegar a entrada e arrumar o tad isso aq
    scanf(" %d", &numcidades);
    scanf(" %d", &comeco);
    Graph *graph = create_graph(numcidades, 0, 1);
    for(int i = 0; i < pa(numcidades - 1); i++){
        scanf(" %d %d %d", &vert1, &vert2, &peso);
        insertEdge(graph, vert1, vert2, peso);
    }

    Answer *ans = tsp(graph, numcidades);
    return 0;
}