
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct viz {
    char noj; /* representa cada letra dentro do nó */
    float peso;
    Viz* prox;
};

struct grafo {
    int nv; /* numero de nos ou vertices */
    int na; /* numero de arestas */
    Viz** viz; /* viz[i] aponta para a lista de arestas incidindo em i */
};

static Viz* criaViz(Viz* head, char noj, float peso) {
    /* insere vizinho no inicio da lista */
    Viz* no = (Viz*) malloc(sizeof(Viz));

    if(no == NULL){
        printf("Erro na alocacao de memoria para o no\n");
        return NULL;
    }

    no->noj = noj;
    no->peso = peso;
    no->prox = head;

    return no;
}

Grafo* grafoCria(int nv, int na) {
    int i;
    Grafo* g = (Grafo *) malloc(sizeof(Grafo));

    if(g == NULL){
        printf("Erro na alocacao de memoria para o grafo\n");
        return NULL;
    }

    g->nv = nv;
    g->na = na;
    g->viz = (Viz **) malloc(sizeof(Viz *) * nv);
    for (i = 0; i < nv; i++){
        g->viz[i] = NULL;
    }
        
    return g;
}

void imprimeGrafo(Grafo *g){
    if(g==NULL){
        printf("Grafo nao existe\n");
        return;
    }
    
    for(int i = 0;i < g->nv;i++){
        printf("Vizinhos do no %d: ", i);
        Viz* viz = g->viz[i];
        while(viz!=NULL){
            printf("%c(%.2f) ", viz->noj, viz->peso);
            viz = viz->prox;
        }
        printf("\n");
    }
}