/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 14/10/2026
Objetivo    : Validar ordens de vagões usando uma pilha.
Dificuldade : Controlar os fluxos de empilhar e desempilhar.
Uso de IA   : Implementação do algoritmo com pilha e I/O.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    while (scanf("%d", &N) == 1 && N != 0) {
        
        int *pilha = (int *)malloc((N + 1) * sizeof(int));
        int *alvo = (int *)malloc(N * sizeof(int));

        while (1) {
            scanf("%d", &alvo[0]);
            
            if (alvo[0] == 0) {
                break;
            }

            for (int i = 1; i < N; i++) {
                scanf("%d", &alvo[i]);
            }

            int topo = -1;      
            int vagon_atual = 1; 
            int possivel = 1;    

            for (int i = 0; i < N; i++) {
                int desejado = alvo[i];

               
                while (vagon_atual <= N && (topo == -1 || pilha[topo] != desejado)) {
                    pilha[++topo] = vagon_atual++;
                }
                
                if (topo >= 0 && pilha[topo] == desejado) {
                    topo--;
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }

    
        printf("\n");

        free(pilha);
        free(alvo);
    }

    return 0;
