/*
Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]. A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor e a 
sua posição dentro do vetor, mostrando esta informação.

Entrada
A primeira linha de entrada contem um único inteiro N (1 < N < 1000), indicando o número de elementos que deverão ser lidos em seguida para o vetor X[N] de 
inteiros. A segunda linha contém cada um dos N valores, separados por um espaço. Vale lembrar que nenhuma entrada 
haverá números repetidos.

10
1 2 3 4 -5 6 7 8 9 10

Saída
A primeira linha apresenta a mensagem “Menor valor:” seguida de um espaço e do menor valor lido na entrada. A segunda linha apresenta a mensagem “Posicao:” seguido
 de um espaço e da posição do vetor na qual se encontra o menor valor lido, lembrando que o vetor inicia na posição zero.

Menor valor: -5
Posicao: 4
*/

#include<stdio.h>

void swap(int array[], int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
int selecao(int array[], int n){
    for(int i = 0; i < n-1; i++){
        int menor = i;
        for(int j = i+1; j < n; j++){
            if(array[j] < array[menor]){
                menor = j;
            }
        } swap(array, i, menor);
    } return array[0];
}
int main(){
    int n;
    //printf("digite n: ");
    scanf("%d", &n);
    int array[n], copia[n];
    for(int i = 0; i < n; i++){
        //printf("digite o numero: ");
        scanf("%d", &array[i]);
        copia[i] = array[i];
    }
    int menor = selecao(array, n);
    for(int i = 0; i < n; i++){
        if(copia[i] == menor){
        printf("Menor valor: %d\n", copia[i]);
        printf("Posicao: %d\n", i);
    }
}
}
