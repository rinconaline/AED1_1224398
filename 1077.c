/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 10/11/2026
Objetivo    : Converter expressões matemáticas da notação infixa para posfixa.
Dificuldade : Entender a precedência dos operadores e como tratar o ^, que é associativo à direita, ao desempilhar operadores da pilha.
Uso de IA   : Usei a IA para entender o funcionamento do algoritmo.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    int n, i, j, top, k;
    char s[4096], st[4096], out[4096], c;

    if (!fgets(s, sizeof(s), stdin)) return 0;
    sscanf(s, "%d", &n);

    for (i = 0; i < n; i++) {
        if (!fgets(s, sizeof(s), stdin)) break;
        top = 0;
        k = 0;
        for (j = 0; s[j] != '\0'; j++) {
            c = s[j];
            if (c == ' ' || c == '\n' || c == '\r' || c == '\t') continue;
            if (c == '(') {
                st[top++] = c;
            } else if (c == ')') {
                while (top > 0 && st[top - 1] != '(') out[k++] = st[--top];
                if (top > 0) top--;
            } else if (prec(c) > 0) {
                while (top > 0 && st[top - 1] != '(' &&
                       (prec(st[top - 1]) > prec(c) ||
                        (prec(st[top - 1]) == prec(c) && c != '^')))
                    out[k++] = st[--top];
                st[top++] = c;
            } else {
                out[k++] = c;
            }
        }
        while (top > 0) out[k++] = st[--top];
        out[k] = '\0';
        printf("%s\n", out);
    }
    return 0;
}
