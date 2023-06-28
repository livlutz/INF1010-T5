/*Lívia Lutz dos Santos - 2211055
Luiza Marcondes Paes Leme - 2210275
*/

typedef struct grafo Grafo;
typedef struct viz Viz;

Viz* criaViz(Viz* head, char noj, int peso);
Grafo* grafoCria(int nv, int na);
void imprimeGrafo(Grafo* g);
void dfs(Grafo*g,char v);
