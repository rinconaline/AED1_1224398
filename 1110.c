/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Aline Mariano Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/en/problems/view/1110
Data        : 17/09/2026
Dificuldade : Entender a lógica da lista.
Uso de IA   : Usei para entender melhor sobre listas
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void enfileirar(Fila *f, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->tamanho++;
}

int desenfileirar(Fila *f) {
    No *temp = f->inicio;
    int valor = temp->valor;

    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
    f->tamanho--;
    return valor;
}

void liberarFila(Fila *f) {
    while (f->inicio != NULL) {
        desenfileirar(f);
    }
}

int main(void) {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        Fila fila;
        inicializarFila(&fila);

        for (int i = 1; i <= n; i++) {
            enfileirar(&fila, i);
        }

        printf("Discarded cards:");

        int primeiro = 1;
        while (fila.tamanho > 1) {
            int descartada = desenfileirar(&fila);

            if (primeiro) {
                printf(" %d", descartada);
                primeiro = 0;
            } else {
                printf(", %d", descartada);
            }

            int moveParaFim = desenfileirar(&fila);
            enfileirar(&fila, moveParaFim);
        }

        printf("\n");
        printf("Remaining card: %d\n", fila.inicio->valor);

        liberarFila(&fila);
    }

    return 0;
}
