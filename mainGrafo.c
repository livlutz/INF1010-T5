/*Lívia Lutz dos Santos - 2211055
Luiza Marcondes Paes Leme - 2210275
*/

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct viz {
    char noj;
    int peso;
    Viz* prox;
};

struct grafo {
    int nv; /* numero de nos ou vertices */
    int na; /* numero de arestas */
    Viz** viz; /* viz[i] aponta para a lista de arestas incidindo em i */
};

int main(void) {

    /*Cria um grafo de 7 vértices e 13 arestas */
    Grafo* g = grafoCria(7, 13);

    /*Guarda o número de vértices do grafo*/
    int numVertices = g->nv;

   /*Array com as letras que estarão contidas em cada vértice e char do caracter do vertice de origem */
    char letras[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'H' },origem = 'A';

    /*OBS : Decidimos colocar A como nó 0 pois ele será a origem 
    para fazer o algoritmo de Dijkstra e o dfs*/
    
    /* Criando vizinhos de A*/
    g->viz[0] = criaViz(g->viz[0], letras[3], 2.0);
    g->viz[0] = criaViz(g->viz[0], letras[2], 4.0);
    g->viz[0] = criaViz(g->viz[0], letras[1], 5.0);
    
    /* Criando vizinhos de B*/
    g->viz[1] = criaViz(g->viz[1], letras[6], 9.0);
    g->viz[1] = criaViz(g->viz[1], letras[4], 6.0);
    g->viz[1] = criaViz(g->viz[1], letras[2], 6.0);
    g->viz[1] = criaViz(g->viz[1], letras[0], 5.0);
    
    /* Criando vizinhos de C */
    g->viz[2] = criaViz(g->viz[2], letras[4], 4.0);
    g->viz[2] = criaViz(g->viz[2], letras[3], 3.0);
    g->viz[2] = criaViz(g->viz[2], letras[1], 6.0);
    g->viz[2] = criaViz(g->viz[2], letras[0], 4.0);
    
    /* Criando vizinhos de D */
    g->viz[3] = criaViz(g->viz[3], letras[5], 9.0);
    g->viz[3] = criaViz(g->viz[3], letras[4], 5.0); 
    g->viz[3] = criaViz(g->viz[3], letras[2], 3.0);
    g->viz[3] = criaViz(g->viz[3], letras[0], 2.0);
   
    /* Criando vizinhos de E */
    g->viz[4] = criaViz(g->viz[4], letras[6], 6.0);
    g->viz[4] = criaViz(g->viz[4], letras[5], 2.0);
    g->viz[4] = criaViz(g->viz[4], letras[3], 5.0);
    g->viz[4] = criaViz(g->viz[4], letras[2], 4.0);
    g->viz[4] = criaViz(g->viz[4], letras[1], 6.0);

    /* Criando vizinhos de F */
    g->viz[5] = criaViz(g->viz[5], letras[6], 3.0);
    g->viz[5] = criaViz(g->viz[5], letras[4], 2.0);
    g->viz[5] = criaViz(g->viz[5], letras[3], 9.0);
    
    /* Criando vizinhos de H */ 
    g->viz[6] = criaViz(g->viz[6], letras[5], 3.0); 
    g->viz[6] = criaViz(g->viz[6], letras[4], 6.0);
    g->viz[6] = criaViz(g->viz[6], letras[1], 9.0);

    printf("Grafo como lista de adjacencias:\n");
    /* Imprime o grafo em ordem alfabética */
    imprimeGrafo(g);

    printf("\nImplementação do algoritmo de Dijkstra a partir do vertice %c:\n", origem);

    /*Imprime passo a passo do algoritmo e resultado*/
    dijkstra(g, origem);

    /*Faz a busca por profundidade no grafo usando percurso por profundidade*/
    printf("\nBusca em profundidade a partir do vertice %c:\n",origem);

    dfs(g, origem);

    return 0;
}
