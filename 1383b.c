#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, soma, produto;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        int **matriz = malloc(9 * sizeof(int *));
        for (int k = 0; k < 9; k++) {
            matriz[k] = malloc(9 * sizeof(int));
        }

        int ver1 = 1, ver2 = 1, ver3 = 1;
        for (int linhas = 0; linhas < 9; linhas++) {
            for (int colunas = 0; colunas < 9; colunas++) {
                scanf("%d", &matriz[linhas][colunas]);
            }
        }
        for (int linhas = 0; linhas < 9; linhas++) {
            soma = 0;
            produto = 1;
            for (int colunas = 0; colunas < 9; colunas++) {
                soma += matriz[linhas][colunas];
                produto *= matriz[linhas][colunas];
            }
            if (soma != 45 || produto != 362880) {
                ver1 = 0;
            }
        }
        for (int colunas = 0; colunas < 9; colunas++) {
            soma = 0;
            produto = 1;
            for (int linhas = 0; linhas < 9; linhas++) {
                soma += matriz[linhas][colunas];
                produto *= matriz[linhas][colunas];
            }

            if (soma != 45 || produto != 362880) {
                ver2 = 0;
            }
        }

        for (int linhaQua = 0; linhaQua < 9; linhaQua += 3) {
            for (int colunaQua = 0; colunaQua < 9; colunaQua += 3) {
                soma = 0;
                produto = 1;
                for (int linha = linhaQua; linha < linhaQua + 3; linha++) {
                    for (int coluna = colunaQua; coluna < colunaQua + 3; coluna++) {
                        soma += matriz[linha][coluna];
                        produto *= matriz[linha][coluna];
                    }
                }
                if (soma != 45 || produto != 362880) {
                    ver3 = 0;
                }
            }
        }

        printf("Instancia %d\n", i);

        if (ver1 == 1 && ver2 == 1 && ver3 == 1) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        for (int k = 0; k < 9; k++) {
            free(matriz[k]);
        }
        free(matriz);
    }

    return 0;
}
