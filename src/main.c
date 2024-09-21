#include <stdio.h>
#include <stdlib.h>
#include "libs/brute.h"
#include "libs/graph.h"

//força bruta ta feito, tenho que fazer o otimizado agora 
//lascou

int *tsp(Graph *graph){
    
}

int main(void){

    int numcidades = 0, vert1 = 0, vert2 = 0, peso = 0, comeco = 0; //peguei do codigo do fernando. só pra pegar a entrada e arrumar o tad isso aq
    scanf(" %d", &numcidades);
    scanf(" %d", &comeco);
    Graph *graph = create_graph(numcidades, 0, 1);
    for (int i = 0; i < pa(numcidades - 1); i++) {
        scanf(" %d %d %d", &vert1, &vert2, &peso);
        insertEdge(graph, vert1, vert2, peso);
    }

    Answer *ans = tsp(graph);
    return 0;
}