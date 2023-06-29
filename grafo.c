/*Lívia Lutz dos Santos - 2211055
Luiza Marcondes Paes Leme - 2210275
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

/*Array com cada letra no grafo*/
char caracteres[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'H' };

/*Array de vertices ja visitados nas buscas*/

int visitados[7] = {0,0,0,0,0,0,0};

/*Struct que reprensenta a lista de adjacências*/

struct viz {
    char noj; /* representa cada letra dentro do nó */
    int peso; /*Representa o peso de cada aresta*/
    Viz* prox; /*Ponteiro para o proximo no*/
};

struct grafo {
    int nv; /* numero de nos ou vertices */
    int na; /* numero de arestas */
    Viz** viz; /* viz[i] aponta para a lista de arestas incidindo em i */
};

/*Função auxiliar que retorna o índice de um caracter no array de caracteres*/
int retornaIndice(char v) {
    int i;
    for (i = 0; i < 7; i++) {
        if (v == caracteres[i]) {
            return i;
        }
    }
}

/*Cria lista encadeada de vizinhos*/
Viz* criaViz(Viz* head, char noj, int peso) {
    /* insere vizinho no inicio da lista */
    Viz* no = (Viz*)malloc(sizeof(Viz));

    if (no == NULL) {
        printf("Erro na alocacao de memoria para o no\n");
        return NULL;
    }

    no->noj = noj;
    no->peso = peso;
    no->prox = head;

    return no;
}

/*Cria um grafo */
Grafo* grafoCria(int nv, int na) {
    int i;
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));

    if (g == NULL) {
        printf("Erro na alocacao de memoria para o grafo\n");
        return NULL;
    }

    g->nv = nv;
    g->na = na;
    g->viz = (Viz**)malloc(sizeof(Viz*) * nv);

    if (g->viz == NULL) {
        printf("Erro na alocacao de memoria para o vizinho\n");
        return NULL;
    }
    
    /*Inicializa a lista com NULL*/
    for (i = 0; i < nv; i++) {
        g->viz[i] = NULL;
    }

    return g;
}

/*Imprime cada vértice do grafo e sua lista de adjacências com os pesos e conteúdos de cada vizinho */
void imprimeGrafo(Grafo* g) {

    if (g == NULL) {
        printf("Grafo nao existe\n");
        return;
    }

    for (int i = 0; i < g->nv; i++) {
        printf("Vizinhos do no %c ", caracteres[i]);
        Viz* viz = g->viz[i];
        while (viz != NULL) {
            printf("-> %c(Peso %d) ", viz->noj, viz->peso);
            viz = viz->prox;
        }
        printf("\n");
    }

}

/*Função que faz a busca em profundidade a partir de um vértice no grafo*/

void dfs(Grafo* g, char v) {

    /*Variavel de contagem e array de caracteres visitados*/

    int i = 0,j = 0;

    i = retornaIndice(v);

    /*Ponteiros para a lista de adjacencias*/

    Viz* no = g->viz[i];

    /*Marcando v como visitado no array e imprimindo sua letra*/

    visitados[i] = 1;
    printf("%c", caracteres[i]);

    /*Percorrendo a lista encadeada*/

    while (no != NULL) {

        /*Pega o indice do caracter contido no vertice no*/
        j = retornaIndice(no->noj);

        /*Se ele ainda nao foi visitado, continuamos a busca a partir dele*/
        if (visitados[j] == 0) {
            dfs(g, no->noj);
        }

        /*Passamos para o proximo no da lista*/
        no = no->prox;
        
    }

}

int indMenorDistancia(int distancias[7], int visitado[7]){

    int min = INT_MAX, minInd = -1;

    for (int i = 0; i < 7; i++) {
        if (visitado[i] == 0 && distancias[i] <= min) {
            min = distancias[i];
            minInd = i;
        }
    }

    return minInd;
}

void dijkstra(Grafo* g, char v) {

    /*Array de distancias da origem aos outros vertices e de visitados*/
    int distancias[7], j = 0, visitado[7] = { 0,0,0,0,0,0,0 };

    /*Inicializando o array com distancias infinitas*/
    for (int i = 0; i < 7; i++) {
        distancias[i] = INT_MAX;
    }
    /*Pega o indice de v (origem)*/
    int i = retornaIndice(v);

    /*Distancia da origem para a origem e 0*/
    distancias[i] = 0;

    for (int cont = 0; cont < 7; cont++) {
        /*Marcando vertice como visitado*/
        visitado[i] = 1;

        /*Adiciona a distância se for menor do que a que já tiver*/
        for (Viz* a = g->viz[i]; a != NULL; a = a->prox) {
            j = retornaIndice(a->noj);
            if (distancias[j] > distancias[i] + a->peso && visitado[j] == 0) {
                distancias[j] = distancias[i] + a->peso;
            }
        }

        /*Imprime as distancias*/
        for (int i = 0; i < 7; i++) {
            printf("%c: %d\n", caracteres[i], distancias[i]);
        }
        printf("\n");

        /*Pega o indice do vertice com menor distancia*/
        i = indMenorDistancia(distancias, visitado);
    }

    printf("Caminho mais curto a partir da origem %c:\n", v);
    /*Imprime as distancias*/
    for (i = 0; i < 7; i++) {
        printf("%c: %d\n", caracteres[i], distancias[i]);
    }

}


