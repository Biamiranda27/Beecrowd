/*
Neste problema você deverá ler 15 valores colocá-los em 2 vetores conforme estes valores forem pares ou ímpares. Só que o tamanho de cada um dos dois vetores é de 
5 posições. Então, cada vez que um dos dois vetores encher, você deverá imprimir todo o vetor e utilizá-lo novamente para os próximos números que forem lidos. 
Terminada a leitura, deve-se imprimir o conteúdo que restou em cada um dos dois vetores, imprimindo primeiro os valores do vetor impar. Cada vetor pode ser 
preenchido tantas vezes quantas for necessário.

Entrada
A entrada contém 15 números inteiros.

1
3
4
-4
2
3
8
2
5
-7
54
76
789
23
98

Saída
Imprima a saída conforme o exemplo abaixo.

par[0] = 4
par[1] = -4
par[2] = 2
par[3] = 8
par[4] = 2
impar[0] = 1
impar[1] = 3
impar[2] = 3
impar[3] = 5
impar[4] = -7
impar[0] = 789
impar[1] = 23
par[0] = 54
par[1] = 76
par[2] = 98

*/

#include <stdio.h>

void imprimirVetor(int vetor[], int tamanho, char* nome) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s[%d] = %d\n", nome, i, vetor[i]);
    }
}

int main() {
    int par[5], impar[5];
    int contPar = 0, contImpar = 0;
    int num;

    for (int i = 0; i < 15; i++) {
        scanf("%d", &num);

        if (num % 2 == 0) {
            par[contPar] = num;
            contPar++;
            if (contPar == 5) {
                imprimirVetor(par, 5, "par");
                contPar = 0; 
            }
        } else {
            impar[contImpar] = num;
            contImpar++;
            if (contImpar == 5) {
                imprimirVetor(impar, 5, "impar");
                contImpar = 0; 
            }
        }
    }

    imprimirVetor(impar, contImpar, "impar");
    imprimirVetor(par, contPar, "par");

    return 0;
}