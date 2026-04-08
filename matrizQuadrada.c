/*
Escreva um algoritmo que leia um inteiro N (0 ≤ N ≤ 100), correspondente a ordem de uma matriz M de inteiros, e construa a matriz de acordo com o exemplo abaixo.

Entrada
A entrada consiste de vários inteiros, um valor por linha, correspondentes as ordens das matrizes a serem construídas. O final da entrada é marcado por um valor de
 ordem igual a zero (0).

1
2
3
4
5
0

Saída
Para cada inteiro da entrada imprima a matriz correspondente, de acordo com o exemplo. Os valores das matrizes devem ser formatados em um campo de tamanho 
3 justificados à direita e separados por espaço. Após o último caractere de cada linha da matriz não deve haver espaços em branco. Após a impressão de cada 
matriz deve ser deixada uma linha em branco.

  1
 
  1   1
  1   1
 
  1   1   1
  1   2   1
  1   1   1
   
  1   1   1   1
  1   2   2   1
  1   2   2   1
  1   1   1   1
 
  1   1   1   1   1
  1   2   2   2   1
  1   2   3   2   1
  1   2   2   2   1
  1   1   1   1   1
 
*/


#include<stdio.h>
int main(){
    int n;
    printf("digite o n: ");
    while(scanf("%d", &n) != 0)
    //int matriz[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("1 ");
        }
        printf("\n");
    }
}