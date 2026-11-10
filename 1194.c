/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 10/11/2026
Objetivo    : Calcular o percurso em pós-ordem de uma árvore binária a partir dos percursos em pré-ordem e em ordem.
Dificuldade : Entender como a raiz do pré-ordem divide o percurso em ordem entre as subárvores esquerda e direita, e montar o pós-ordem recursivamente.
Uso de IA   : Entender como funciona a recursão.
-------------------------------------------------------------------------- */

#include <stdio.h>

void pos(char *pre, char *in, int n, char *out, int *k) {
    int i;
    if (n <= 0) return;
    for (i = 0; i < n && in[i] != pre[0]; i++);
    pos(pre + 1, in, i, out, k);
    pos(pre + 1 + i, in + i + 1, n - i - 1, out, k);
    out[(*k)++] = pre[0];
}

int main() {
    int c, n, k;
    char a[64], b[64], out[64];

    scanf("%d", &c);
    while (c--) {
        scanf("%d %s %s", &n, a, b);
        k = 0;
        pos(a, b, n, out, &k);
        out[k] = '\0';
        printf("%s\n", out);
    }
    return 0;
}
