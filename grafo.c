/*Lívia Lutz dos Santos - 2211055
Luiza Marcondes Paes Leme - 2210275
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

/*Array com cada letra no grafo*/
char caracteres[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'H' };

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

struct pilha{
    int topo; /* topo da pilha */
    char elementos[7]; /* elementos da pilha */
};


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

    for (i = 0; i < nv; i++) {
        g->viz[i] = NULL;
    }

    return g;
}

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

void dfs(Grafo*g,char v, Pilha pilha) {

    int i = 0, visitado[7] = { 0,0,0,0,0,0,0 }, j = 0;

    /*Pegar o índice da letra do parâmetro*/
    for (; i < 7; i++) {
        if (v == caracteres[i]) {
            break;
        }
    }

    /*Pega o ponteiro para lista de adjacências*/
    Viz* w = g->viz[i];

    for (Viz* a = w; a != NULL; a = a->prox) {
        /*Guarda o char do no*/
        char c = a->noj;

        int ip = pilha.topo;

        /* Verifica se aquele elemento já está na pilha */
        while (ip >= 0) {
            if (pilha.elementos[ip] == c) {
                break;
            }
            ip--;
        }

        int ind = 0;
        /*Pegar o índice da letra do parâmetro*/
        for (; ind < 7; ind++) {
            if (v == caracteres[ind]) {
                break;
            }
        }

        /* Se o elemento não está na pilha, o adicionamos */
        if (ip < 0 && visitado[ind] == 1) {
            pilha.topo++;
            pilha.elementos[pilha.topo] = c;
        }

    }

    /* Marcamos o no como visitado e o imprimimos */
    visitado[i] = 1;
    printf("%c - Pilha: ", v);

    for (int i = 0; i <= pilha.topo; i++) {
        printf("%c ", pilha.elementos[i]);
    }
    printf("\n");

    /* Enquanto a pilha não estiver vazia */
    if (pilha.topo > 0) {
        /* Pega o último elemento da pilha */
        char c = pilha.elementos[pilha.topo];

        /* Desempilha */
        pilha.topo--;

        /* Chama a função dfs novamente */
        dfs(g, c, pilha);
    }

}


