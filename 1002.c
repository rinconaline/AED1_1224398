/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Aline Mariane Rincon
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1002
Data        : 14/10/2026
Objetivo    : Calcular a área de um círculo dada a medida do raio.
Dificuldade : Sem dificuldade.
Uso de IA   : Não.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main()
{
    double raio;
    const double n=3.14159;

    scanf("%lf", &raio);
    double area=n*raio*raio;
    printf("A=%.4lf\n", area);
    
    return 0;
}
