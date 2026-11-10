/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 10/11/2026
Objetivo    : Listar todos os componentes conexos de um grafo, com os vértices de cada componente em ordem crescente, e contar quantos componentes existem.
Dificuldade : Entender como a busca em profundidade (DFS) encontra os vértices de cada componente e imprimir no formato exigido, com a vírgula depois de cada vértice.
Uso de IA   : Para entender como os componentes conexos são encontrados.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

int adj[26][26];
int comp[26];
int nv;

void dfs(int u, int id) {
    int w;
    comp[u] = id;
    for (w = 0; w < nv; w++)
        if (adj[u][w] && comp[w] == 0) dfs(w, id);
}

int main() {
    int n, t, e, i, u, id;
    char a, b;

    scanf("%d", &n);
    for (t = 1; t <= n; t++) {
        scanf("%d %d", &nv, &e);
        memset(adj, 0, sizeof(adj));
        memset(comp, 0, sizeof(comp));
        for (i = 0; i < e; i++) {
            scanf(" %c %c", &a, &b);
            adj[a - 'a'][b - 'a'] = 1;
            adj[b - 'a'][a - 'a'] = 1;
        }
        printf("Case #%d:\n", t);
        id = 0;
        for (i = 0; i < nv; i++) {
            if (comp[i] == 0) {
                id++;
                dfs(i, id);
                for (u = 0; u < nv; u++)
                    if (comp[u] == id) printf("%c,", 'a' + u);
                printf("\n");
            }
        }
        printf("%d connected components\n\n", id);
    }
    return 0;
}
