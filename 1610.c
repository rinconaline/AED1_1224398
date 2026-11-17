/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1061
Data        : 17/11/2026
Objetivo    : Detectar ciclos em dependências de documentos usando DFS.
Dificuldade : Controlar os estados dos vértices (não visitado, visitando e finalizado) em grafo direcionado.
Uso de IA   : Implementação da lista de adjacência e da busca em profundidade (DFS).

-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10005

typedef struct No {
    int destino;
    struct No *prox;
} No;

No *lista[MAX];
int estado[MAX];

void adicionar(int origem, int destino) {
    No *novo = malloc(sizeof(No));
    novo->destino = destino;
    novo->prox = lista[origem];
    lista[origem] = novo;
}

bool tem_ciclo(int atual) {
    estado[atual] = 1;

    for (No *vizinho = lista[atual]; vizinho != NULL; vizinho = vizinho->prox) {
        int destino = vizinho->destino;

        if (estado[destino] == 1) return true;
        if (estado[destino] == 0 && tem_ciclo(destino)) return true;
    }

    estado[atual] = 2;
    return false;
}

int main() {
    int testes;
    if (scanf("%d", &testes) != 1) return 0;

    while (testes--) {
        int docs, deps, a, b;
        scanf("%d %d", &docs, &deps);

        for (int i = 1; i <= docs; i++) {
            lista[i] = NULL;
            estado[i] = 0;
        }

        while (deps--) {
            scanf("%d %d", &a, &b);
            adicionar(a, b);
        }

        bool ciclo = false;
        for (int i = 1; i <= docs && !ciclo; i++) {
            if (estado[i] == 0 && tem_ciclo(i)) {
                ciclo = true;
            }
        }

        printf(ciclo ? "SIM\n" : "NAO\n");
    }

    return 0;
}
