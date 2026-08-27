/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Aline Mariano Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/en/problems/view/1080
Data        : 27/08/2026
Dificuldade : Entender a lógica do if (i==1).
Uso de IA   : Não usei.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main()
{
    int num, maior, posicao;
    
    for(int i=1; i<=100; i++){
        
        scanf("%d", &num);
        
        if ( i==1){
            maior = num;
            posicao = i;
        }
        else {
            if(maior<num){
                maior = num;
                posicao = i;
            }
        }
        
        
    }

    printf("%d\n", maior);
    printf("%d\n", posicao);

    return 0;
}
