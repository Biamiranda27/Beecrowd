/*
Neste problema sua tarefa será ler vários números e em seguida dizer quantas vezes cada número aparece na entrada de dados, ou seja, deve-se escrever cada um dos
 valores distintos que aparecem na entrada por ordem crescente de valor.

Entrada
A entrada contém apenas 1 caso de teste. A primeira linha de entrada contem um único inteiro N, que indica a quantidade de valores que serão lidos para 
X (1 ≤ X ≤ 2000) logo em seguida. Com certeza cada número não aparecerá mais do que 20 vezes na entrada de dados.

7
8
10
8
260
4
10
10

Saída
Imprima a saída de acordo com o exemplo fornecido abaixo, indicando quantas vezes cada um deles aparece na entrada por ordem crescente de valor.
4 aparece 1 vez(es)
8 aparece 2 vez(es)
10 aparece 3 vez(es)
260 aparece 1 vez(es)
*/

#include<stdio.h>

void swap(int array[], int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
void bubble(int array[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(array[j+1] < array[j]){
                swap(array, j, j+1);
            }
        }
    }
}
int main(){
    int n;
    //printf("digite n: ");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        //printf("digite o numero: ");
        scanf("%d", &array[i]);
    }
    bubble(array, n);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(array[i] == array[i+1]){
            count++;
        } else{
            printf("%d aparece %d vez(es)\n", array[i], count+1);
            count = 0;
        }
    }
}