/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 10/11/2026
Objetivo    : Implementar uma árvore binária de busca com os comandos de inserção, busca e impressão em pré-ordem, em ordem e pós-ordem.
Dificuldade : Ler os comandos até o fim da entrada (EOF) e imprimir cada linha sem espaço sobrando no final.
Uso de IA   : Para confirmar se minha lógica estava certa.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char v;
    struct no *esq, *dir;
} no;

no *inserir(no *r, char x) {
    if (r == NULL) {
        no *n = malloc(sizeof(no));
        n->v = x;
        n->esq = NULL;
        n->dir = NULL;
        return n;
    }
    if (x < r->v) r->esq = inserir(r->esq, x);
    else if (x > r->v) r->dir = inserir(r->dir, x);
    return r;
}

int buscar(no *r, char x) {
    while (r != NULL) {
        if (x == r->v) return 1;
        r = (x < r->v) ? r->esq : r->dir;
    }
    return 0;
}

void pre(no *r, int *p) {
    if (r == NULL) return;
    printf(*p ? "%c" : " %c", r->v);
    *p = 0;
    pre(r->esq, p);
    pre(r->dir, p);
}

void em(no *r, int *p) {
    if (r == NULL) return;
    em(r->esq, p);
    printf(*p ? "%c" : " %c", r->v);
    *p = 0;
    em(r->dir, p);
}

void pos(no *r, int *p) {
    if (r == NULL) return;
    pos(r->esq, p);
    pos(r->dir, p);
    printf(*p ? "%c" : " %c", r->v);
    *p = 0;
}

void liberar(no *r) {
    if (r == NULL) return;
    liberar(r->esq);
    liberar(r->dir);
    free(r);
}

int main() {
    char cmd[16], x;
    int p;
    no *raiz = NULL;

    while (scanf("%15s", cmd) == 1) {
        if (strcmp(cmd, "I") == 0) {
            scanf(" %c", &x);
            raiz = inserir(raiz, x);
        } else if (strcmp(cmd, "P") == 0) {
            scanf(" %c", &x);
            if (buscar(raiz, x)) printf("%c existe\n", x);
            else printf("%c nao existe\n", x);
        } else if (strcmp(cmd, "INFIXA") == 0) {
            p = 1;
            em(raiz, &p);
            printf("\n");
        } else if (strcmp(cmd, "PREFIXA") == 0) {
            p = 1;
            pre(raiz, &p);
            printf("\n");
        } else if (strcmp(cmd, "POSFIXA") == 0) {
            p = 1;
            pos(raiz, &p);
            printf("\n");
        }
    }
    liberar(raiz);
    return 0;
}
