/*
Leia 3 valores inteiros e ordene-os em ordem crescente. No final, mostre os valores em ordem crescente, uma linha em branco e em seguida, os valores na sequência 
como foram lidos.

Entrada
A entrada contem três números inteiros.

7 21 -14

Saída
Imprima a saída conforme foi especificado.

-14
7
21

7
21
-14
*/

#include <stdio.h>

void swap(int array[], int i, int j){
    int tmp = array[i];
    array[i]= array[j];
    array[j] = tmp;
}
void selecao(int array[], int n){
    for(int i = 0; i < n-1; i++){
        int menor = i;
        for(int j = i+1; j < n; j++){
            if(array[j] < array[menor]){
                menor = j;
            }
        } swap(array, i, menor);
    }
}

int main(){
 int n = 3;
 int array[n], copia[n];
 for(int i = 0; i < n; i++){
    //printf("digite o numero: ");
    scanf("%d", &array[i]);
    copia[i] = array[i];
    }
    selecao(array, n);
    for(int i = 0; i < n; i++){
        printf("%d\n", array[i]);
    } 
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d\n", copia[i]);
    }
}