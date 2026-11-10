/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 10/11/2026
Objetivo    : Construir uma árvore binária de busca a partir de uma sequência de números e imprimir os percursos em pré-ordem, em ordem e em pós-ordem.
Dificuldade : Entender a recursão da inserção e dos percursos.
Uso de IA   : Usei a IA para entender como funciona a recursão.
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

void pre(no *r, int *p) {
    if (r == NULL) return;
    printf(*p ? "%d" : " %d", r->v);
    *p = 0;
    pre(r->esq, p);
    pre(r->dir, p);
}

void em(no *r, int *p) {
    if (r == NULL) return;
    em(r->esq, p);
    printf(*p ? "%d" : " %d", r->v);
    *p = 0;
    em(r->dir, p);
}

void pos(no *r, int *p) {
    if (r == NULL) return;
    pos(r->esq, p);
    pos(r->dir, p);
    printf(*p ? "%d" : " %d", r->v);
    *p = 0;
}

void liberar(no *r) {
    if (r == NULL) return;
    liberar(r->esq);
    liberar(r->dir);
    free(r);
}

int main() {
    int c, n, i, t, x, p;
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
        printf("Pre.: ");
        p = 1;
        pre(raiz, &p);
        printf("\nIn..: ");
        p = 1;
        em(raiz, &p);
        printf("\nPost: ");
        p = 1;
        pos(raiz, &p);
        printf("\n\n");
        liberar(raiz);
    }
    return 0;
}
