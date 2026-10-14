#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int casas[], int n, int valor) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (casas[meio] == valor) {
            return meio; 
        }
        
        if (casas[meio] < valor) {
            inicio = meio + 1; 
        } else {
            fim = meio - 1;    
        }
    }

    return -1;
}

int main() {
    int N, M;

    if (scanf("%d %d", &N, &M) != 2) return 0;

    int *casas = (int *)malloc(N * sizeof(int));
    if (casas == NULL) return 1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }

    long long tempo_total = 0;
    int pos_atual = 0;
    for (int i = 0; i < M; i++) {
        int destino;
        scanf("%d", &destino);

        int pos_destino = buscaBinaria(casas, N, destino);

        int distancia = pos_destino - pos_atual;
        if (distancia < 0) {
            distancia = -distancia; 
        }

        tempo_total += distancia;

        pos_atual = pos_destino;
    }

    printf("%lld\n", tempo_total);

    free(casas);

    return 0;
}
