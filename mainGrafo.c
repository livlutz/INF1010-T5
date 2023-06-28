#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct viz {
    char noj;
    float peso;
    Viz* prox;
};

struct grafo {
    int nv; /* numero de nos ou vertices */
    int na; /* numero de arestas */
    Viz** viz; /* viz[i] aponta para a lista de arestas incidindo em i */
};


int main(void){
    
    int numVertices;

    /*Cria um grafo de 7 vértices e 13 arestas */
    Grafo* g = grafoCria(7, 13);

    numVertices = g->nv;

    /*Cria as arestas do grafo */

    char letras[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'H'};

    /* Criando vizinhos de A*/
    g->viz[0] = criaViz(g->viz[0], letras[1], 5.0);
    g->viz[0] = criaViz(g->viz[0], letras[2], 4.0);
    g->viz[0] = criaViz(g->viz[0], letras[3], 2.0);

    /* Criando vizinhos de B*/
    g->viz[1] = criaViz(g->viz[1], letras[0], 5.0);
    g->viz[1] = criaViz(g->viz[1], letras[2], 6.0);
    g->viz[1] = criaViz(g->viz[1], letras[4], 6.0);
    g->viz[1] = criaViz(g->viz[1], letras[6], 9.0);

    /* Criando vizinhos de C */
    g->viz[2] = criaViz(g->viz[2], letras[0], 4.0);
    g->viz[2] = criaViz(g->viz[2], letras[1], 6.0);
    g->viz[2] = criaViz(g->viz[2], letras[3], 3.0);
    g->viz[2] = criaViz(g->viz[2], letras[4], 4.0);

    /* Criando vizinhos de D */
    g->viz[3] = criaViz(g->viz[3], letras[0], 2.0);
    g->viz[3] = criaViz(g->viz[3], letras[2], 3.0);
    g->viz[3] = criaViz(g->viz[3], letras[4], 5.0);
    g->viz[3] = criaViz(g->viz[3], letras[5], 9.0);

    /* Criando vizinhos de E */
    g->viz[4] = criaViz(g->viz[4], letras[1], 6.0);
    g->viz[4] = criaViz(g->viz[4], letras[2], 4.0);
    g->viz[4] = criaViz(g->viz[4], letras[3], 5.0);
    g->viz[4] = criaViz(g->viz[4], letras[5], 2.0);
    g->viz[4] = criaViz(g->viz[4], letras[6], 6.0);

    /* Criando vizinhos de F */
    g->viz[5] = criaViz(g->viz[5], letras[3], 9.0);
    g->viz[5] = criaViz(g->viz[5], letras[4], 2.0);
    g->viz[5] = criaViz(g->viz[5], letras[6], 3.0);

    /* Criando vizinhos de H */
    g->viz[6] = criaViz(g->viz[6], letras[1], 9.0);
    g->viz[6] = criaViz(g->viz[6], letras[4], 6.0);
    g->viz[6] = criaViz(g->viz[6], letras[5], 3.0);

    imprimeGrafo(g);


    return 0;
}