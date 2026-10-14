/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1340
Data        : 14/10/2026
Objetivo    : Identificar se a estrutura e pilha, fila, fila de prioridade ou indefinida.
Dificuldade : Simular tres estruturas simultaneamente e controlar as flags de validacao.
Uso de IA   : Implementacao do algoritmo de simulacao das estruturas de dados.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int pilha[1005], topo = -1;
        int fila[1005], inicio = 0, fim = 0;
        int pqueue[1005], tam = 0;

        int eh_pilha = 1;
        int eh_fila = 1;
        int eh_pqueue = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d", &op);

            if (op == 1) {
                scanf("%d", &x);
                if (eh_pilha) pilha[++topo] = x;
                if (eh_fila) fila[fim++] = x;
                if (eh_pqueue) {
                    pqueue[tam++] = x;
                    int k = tam - 1;
                    while (k > 0) {
                        int pai = (k - 1) / 2;
                        if (pqueue[k] > pqueue[pai]) {
                            int temp = pqueue[k];
                            pqueue[k] = pqueue[pai];
                            pqueue[pai] = temp;
                            k = pai;
                        } else {
                            break;
                        }
                    }
                }
            } else {
                scanf("%d", &x);

                if (eh_pilha) {
                    if (topo < 0 || pilha[topo] != x) {
                        eh_pilha = 0;
                    } else {
                        topo--;
                    }
                }

                if (eh_fila) {
                    if (inicio >= fim || fila[inicio] != x) {
                        eh_fila = 0;
                    } else {
                        inicio++;
                    }
                }

                if (eh_pqueue) {
                    if (tam <= 0 || pqueue[0] != x) {
                        eh_pqueue = 0;
                    } else {
                        pqueue[0] = pqueue[tam - 1];
                        tam--;
                        int k = 0;
                        while (2 * k + 1 < tam) {
                            int esq = 2 * k + 1;
                            int dir = 2 * k + 2;
                            int maior = esq;
                            if (dir < tam && pqueue[dir] > pqueue[esq]) {
                                maior = dir;
                            }
                            if (pqueue[maior] > pqueue[k]) {
                                int temp = pqueue[k];
                                pqueue[k] = pqueue[maior];
                                pqueue[maior] = temp;
                                k = maior;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }

        int total = eh_pilha + eh_fila + eh_pqueue;

        if (total == 0) {
            printf("impossible\n");
        } else if (total > 1) {
            printf("not sure\n");
        } else if (eh_pilha) {
            printf("stack\n");
        } else if (eh_fila) {
            printf("queue\n");
        } else {
            printf("priority queue\n");
        }
    }

    return 0;
}
