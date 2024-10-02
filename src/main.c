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

int distanciamin(Graph *graph, int numcidades){ //aqui vou calcular a distancia minima que duas cidades podem ter (uso a partir da primeira cidade e só)
    int aux = 0, soma = 0; //o auxiliar vai pegar o menor valor da linha/coluna . a soma vou usar pra achar essa distancia minima aí

    for(int i = 0; i < numcidades; i++){
        aux = getWeightVertice(graph, i, 0); //pego ja o primeiro numero da "matriz" pra comparar dps
        for(int j = 1; j < numcidades; j++){ //aq começo no 1 pq ja tenho o valor do 0 da linha de cima
            if(aux > getWeightVertice(graph, i, j) && aux != INT_MAX) aux = getWeightVertice(graph, i, j); //procuro um valor menor na linha
        } //saindo daqui eu tenho o menor valor da linha
        if((!aux) || aux == INT_MAX) break; //se o menor valor na linha é 0 nao vou fazer nenhuma alteração na frente (ou caso seja INT_MAX no bagulho), entao dá break
        soma += aux; //a soma basicamente armazena a soma dos menores valores das linhas e colunas
        for(int j = 0; j < numcidades; j++){ //percorro a mesma linha pra mexer aq
            insertEdge(graph, i, j, getWeightVertice(graph, i, j) - aux); //subtraio o menor valor da linha em geral dali
        }
    }

    for(int i = 0; i < numcidades; i++){ //mesma logica de cima, só muda que to mexendo com coluna e nao linha
        aux = getWeightVertice(graph, 0, i); 
        for(int j = 1; j < numcidades; j++){ 
            if(aux > getWeightVertice(graph, j, i) && aux != INT_MAX) aux = getWeightVertice(graph, j, i); 
        } 
        if((!aux) || aux == INT_MAX) break;
        soma += aux;
        for(int j = 0; j < numcidades; j++){ 
            insertEdge(graph, j, i, getWeightVertice(graph, j, i) - aux); 
        }
    }//dps disso tudo tenho teoricamente uma "matriz reduzida" e a soma de todos os minimos que achei no caminho
    
    return soma;
}

int distcidades(Graph *graph, int numcidades, int distmin, int x, int y){ //calcula distancia para as proximas cidades (dps da primeira)
    int custoatual = getWeightVertice(graph, x, y); //vou usar dps pra retornar o custo estimado final
    int altera = 0, aux, flag0 = 0, flagmax = 1, auxmenor; //altera vai guardar uma possivel alteraçao nova que eu faça aq, vou precisar pra estimar o custo dps; aux vai servir pra ver os valores dos vertices no geral; flag0 me diz se teve algum 0 na situaçao; flagmax me diz se teve algo diferente de INT_MAX na situaçao; auxmenor guarda o menor valor na situação 
    for(int j = 0; j < numcidades; j++){ //coloco todos os vertices dessa linha como INT_MAX
        insertEdge(graph, x, j, INT_MAX);
    }
    for(int i = 0; i < numcidades; i++){ //coloco todos os vertices dessa coluna como INT_MAX
        insertEdge(graph, i, y, INT_MAX);
    }
    insertEdge(graph, y, x, INT_MAX); //coloco o vertice de y pra x como INT_MAX tbm (teoricamente o grafo do fernando ja faz isso quando uso x pra y mas so pra garantir)

    for(int i = 0; i < numcidades; i++){
        auxmenor = getWeightVertice(graph, i, 0);
        for(int j = 1; j < numcidades; j++){
            aux = getWeightVertice(graph, i, j);
            if(auxmenor > aux) auxmenor = aux; //toda vez que acho um menor eu guardo no auxmenor
            if(aux != INT_MAX) flagmax = 0; //caso eu ache algo diferente de INT_MAX na linha eu marco a flag como 0
            if(!aux) flag0 = 1; //caso eu ache um 0 eu marco a flag (fica como menor valor do bagulho)
        }
        if(flag0 || flagmax){ //caso tenha tido um 0 na linha ou se a linha foi inteira de INT_MAX eu nao altero nada
            flag0 = 0; //só volto as flags pro valor original pra continuar as comparaçoes dps
            flagmax = 1;
            continue; 
        }else{ //caso o menor valor na linha nao tenha sido 0 && a linha nao é cheia de INT_MAX, preciso subtrair o menor valor do bagulho de todos os presentes na linha
            altera += auxmenor;
            for(int a = 0; a < numcidades; a++){
                if(getWeightVertice(graph, i, a) == INT_MAX) continue; //caso seja INT_MAX no bagulho eu nao subtraio, continua como max mesmo
                insertEdge(graph, i, a, getWeightVertice(graph, i, a) - auxmenor); //recoloco o valor desse vertice como ele menos o valor minimo que achei ali em cima
            }
        }
    }

    for(int j = 0; j < numcidades; j++){ //repito todo o processo de cima só que agora analisando em colunas 
        auxmenor = getWeightVertice(graph, 0, j);
        for(int i = 1; i < numcidades; i++){
            aux = getWeightVertice(graph, i, j);
            if(auxmenor > aux) auxmenor = aux; 
            if(aux != INT_MAX) flagmax = 0; 
            if(!aux) flag0 = 1; 
        }
        if(flag0 || flagmax){ 
            flag0 = 0; 
            flagmax = 1;
            continue; 
        }else{ 
            for(int a = 0; a < numcidades; a++){
                if(getWeightVertice(graph, a, j) == INT_MAX) continue; 
                insertEdge(graph, a, j, getWeightVertice(graph, a, j) - auxmenor); 
            }
        }
    }

    return (distmin + custoatual + altera); //retorno a distancia minima que calculei na primeira vez + custo pra chegar nessa cidade atual + qualquer alteraçao que eu tenha feito aqui
}

void diagonal(Graph *graph, int numcidades){ //so coloca a diagonal principal com o tamanho maximo
    for(int i = 0; i < numcidades; i++){
        insertEdge(graph, i, i, INT_MAX);
    }

    return;
}

Answer *tsp(Graph *graph, int numcidades, int primeira){
    diagonal(graph, numcidades); //arrumo a diagonal principal pra ter um tamanho grandao (preciso disso no algoritmo)
    int distmin = distanciamin(graph, numcidades);
    int guia[numcidades]; //esse guia aq eu vou usar pra me guiar pelo caminho que to fazendo
    for(int i = 0; i < numcidades; i++) guia[i] = i + 1; //vou deixar no guia todas as cidades disponiveis


}

//preciso criar uma funçao que me guie pelas cidades. ja tenho pronto tudo que estima as distancias, so quero uma funçao que me faça andar pelas cidades

int main(void){

    int numcidades = 0, vert1 = 0, vert2 = 0, peso = 0, comeco = 0; //peguei do codigo do fernando. só pra pegar a entrada e arrumar o tad isso aq
    scanf(" %d", &numcidades);
    scanf(" %d", &comeco);
    Graph *graph = create_graph(numcidades, 0, 1);
    for(int i = 0; i < pa(numcidades - 1); i++){
        scanf(" %d %d %d", &vert1, &vert2, &peso);
        insertEdge(graph, vert1, vert2, peso);
    }

    Answer *ans = tsp(graph, numcidades, comeco);
    return 0;
}