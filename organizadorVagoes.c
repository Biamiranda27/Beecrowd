/*
Na estação de trem você ainda pode encontrar o último dos “organizadores de vagões”. Um Organizador de vagões um empregado cujo trabalho é apenas reordenar os 
vagões do trem, trocando-os de posição. Uma vez que os vagões são organizados em uma ordem considerada ótima, o condutor pode desconectar cada vagão e colocá-los 
na estação.

O título “organizador de vagões” é dado à pessoa que realiza esta tarefa, cuja estação fica perto de uma ponte. Ao invés da ponte poder subir ou descer, ela roda 
sobre um pilar que fica no centro do rio. Após rodar 90 graus, os barcos podem passar na esquerda ou direita dela. O Primeiro organizador de vagões descobriu que 
girando a ponte 180 graus com dois vagões em cima dela, é possível a troca de lugar entre os dois vagões. Obviamente a ponte pode operar no máximo com dois vagões 
sobre ela.

Agora que quase todos os organizadores de vagões já faleceram, a estação gostaria de automatizar esta operação. Parte do programa a ser desenvolvido é uma rotina 
que decide para um dado trem com um determinado número de vagões, o número de trocas entre trens adjacentes que são necessárias para que o  trem fique ordenado. 
Sua tarefa é criar tal rotina.

Entrada
A entrada contém na primeira linha o número de caso de testes (N). Cada caso de teste consiste de duas linhas de entrada. A primeira linha de um caso de teste 
contém um inteiro L, determinando o tamanho do trem (0 ≤ L ≤ 50). A segunda linha de um caso de teste contém uma permutação dos números 1 até L, indicando a 
ordem corrente dos vagões. Os vagões devem ser ordenados de forma que o vagão 1 venha por primeiro, depois o 2, etc, com o vagão L vindo por último.

3
3
1 3 2
4
4 3 2 1
2
2 1

Saída
Para cada caso de teste imprima a sentença: 'Optimal train swapping takes S swaps.' onde S é um inteiro.

Optimal train swapping takes 1 swaps.
Optimal train swapping takes 6 swaps.
Optimal train swapping takes 1 swaps.
*/


#include<stdio.h>

void swap(int array[], int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
int bubble(int array[], int n){
    int count = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(array[j+1] < array[j]){
                swap(array, j, j+1);
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n;
    //printf("digite o valor de n: ");
    scanf("%d", &n);
    while(n > 0){
        int l;
        //printf("digite l: ");
        scanf("%d", &l);
        int array[l];
        for(int i = 0; i < l; i++){
            //printf("digite um valor: ");
            scanf("%d", &array[i]);
        }
        int count = bubble(array, l);
        printf("Optimal train swapping takes %d swaps.\n", count);
        n--;
    }
}