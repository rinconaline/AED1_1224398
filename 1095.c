/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Aline Mariano Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/en/problems/view/1095
Data        : 22/10/2026
Dificuldade : Entender o padrão da sequência
Uso de IA   : Não usei.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main (){
    int i=1;
    for (int j=60; j>=0; j=j-5){
        printf("I=%d J=%d\n", i, j);
        i=i+3;
    }
    

}
