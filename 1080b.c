/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Aline Mariano Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/en/problems/view/1080
Data        : 27/08/2026
Dificuldade : Entender o uso de ponteiros.
Uso de IA   : Aprender a usar o malloc.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main (){
    int n= 100;
    
    int *v = malloc(n*sizeof(int));
    if (v==NULL){
        printf("Falha!");
        return 1;
    }
    
    for (int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    int maior = v[0];
    int posicao = 1;
    
    for (int i=1; i<n; i++){
        if (v[i]> maior ){
            maior = v[i];
            posicao = i +1;
        }
    }
     printf("%d\n", maior);
    printf("%d\n", posicao);

    free(v);

    return 0;
    
}
