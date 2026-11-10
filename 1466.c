/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 10/11/2026
Objetivo    : Construir uma árvore binária de busca a partir de uma sequência de números e imprimir o percurso em nível (largura) usando uma fila.
Dificuldade : Entender que o percurso em nível não é recursivo e usa uma fila (FIFO), e imprimir sem espaço sobrando no fim da linha.
Uso de IA   : Usei a IA para entender como funciona a fila no percurso.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *esq, *dir;
} no;

no *inserir(no *r, int x) {
    if (r == NULL) {
        no *n = malloc(sizeof(no));
        n->v = x;
        n->esq = NULL;
        n->dir = NULL;
        return n;
    }
    if (x < r->v) r->esq = inserir(r->esq, x);
    else r->dir = inserir(r->dir, x);
    return r;
}

void nivel(no *raiz) {
    no *fila[512], *atual;
    int ini = 0, fim = 0, primeiro = 1;

    if (raiz == NULL) return;
    fila[fim++] = raiz;
    while (ini < fim) {
        atual = fila[ini++];
        printf(primeiro ? "%d" : " %d", atual->v);
        primeiro = 0;
        if (atual->esq != NULL) fila[fim++] = atual->esq;
        if (atual->dir != NULL) fila[fim++] = atual->dir;
    }
}

void liberar(no *r) {
    if (r == NULL) return;
    liberar(r->esq);
    liberar(r->dir);
    free(r);
}

int main() {
    int c, n, i, t, x;
    no *raiz;

    scanf("%d", &c);
    for (t = 1; t <= c; t++) {
        scanf("%d", &n);
        raiz = NULL;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            raiz = inserir(raiz, x);
        }
        printf("Case %d:\n", t);
        nivel(raiz);
        printf("\n\n");
        liberar(raiz);
    }
    return 0;
}
