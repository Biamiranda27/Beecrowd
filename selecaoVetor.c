/*
Faça um programa que leia um vetor A[100]. No final, mostre todas as posições do vetor que armazenam um valor menor ou igual a 10 e o 
valor armazenado em cada uma das posições.

Entrada
A entrada contém 100 valores, podendo ser inteiros, reais, positivos ou negativos.

0
-5
63
-8.5

Saída
Para cada valor do vetor menor ou igual a 10, escreva "A[i] = x", onde i é a posição do vetor e x é o valor armazenado na posição, com 
uma casa após o ponto decimal.

A[0] = 0.0
A[1] = -5.0
A[3] = -8.5
*/


#include<stdio.h>
int main(){
    int n = 4;
    double array[n];
    for(int i = 0; i < n; i++){
        printf("digite o valor: ");
        scanf("%lf", &array[i]);
    }
    for(int i = 0; i < n; i++){
        if(array[i] <= 10){
            printf("A[%d] = %.1lf\n", i, array[i]);
        }
    }
}
