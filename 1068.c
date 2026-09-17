/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Aline Mariano Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/en/problems/view/1068
Data        : 17/09/2026
Dificuldade : Entender a lógica de pilhas.
Uso de IA   : Para entender melhor o funcionamento de pilhas.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

#define TAM_MAX 1100  

typedef struct {
    char itens[TAM_MAX];
    int topo; 
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, char c) {
    p->topo++;
    p->itens[p->topo] = c;
}

int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        return 0;
    }
    p->topo--;
    return 1;
}

int main(void) {
    char linha[TAM_MAX];

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        Pilha pilha;
        inicializarPilha(&pilha);

        int correta = 1;
        int tamanho = (int) strlen(linha);

        for (int i = 0; i < tamanho; i++) {
            char c = linha[i];

            if (c == '(') {
                empilhar(&pilha, c);
            } else if (c == ')') {
                if (!desempilhar(&pilha)) {
                    correta = 0;
                }
            }
        }
        if (!pilhaVazia(&pilha)) {
            correta = 0;
        }

        printf("%s\n", correta ? "correct" : "incorrect");
    }

    return 0;
}
