/*
Considerando a entrada de valores inteiros não negativos, ordene estes valores segundo o seguinte critério:
Primeiro os Pares
Depois os Ímpares
Sendo que deverão ser apresentados os pares em ordem crescente e depois os ímpares em ordem decrescente.

Entrada

A primeira linha de entrada contém um único inteiro positivo N (1 < N <= 105) Este é o número de linhas de entrada que vem logo a seguir. 
As próximas N linhas conterão, cada uma delas, um valor inteiro não negativo.

10
4
32
34
543
3456
654
567
87
6789
98

Saída

Apresente todos os valores lidos na entrada segundo a ordem apresentada acima. Cada número deve ser impresso em uma linha, conforme 
exemplo abaixo.

4
32
34
98
654
3456
6789
567
543
87

*/

#include<stdio.h>


void swap(int array[], int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void selecaoCrescente(int array[], int n){
    for(int i = 0; i < n-1; i++){
        int menor = i;
        for(int j = i+1; j < n; j++){
            if(array[j] < array[menor]){
                menor = j;
            }
        }
        swap(array, i, menor);
    }
}

void selecaoDecrescente(int array[], int n){
    for(int i = 0; i < n-1; i++){
        int maior = i;
        for(int j = i+1; j < n; j++){
            if(array[j] > array[maior]){
                maior = j;
            }
        }
        swap(array, i, maior);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int array[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    int pares[n], impares[n];
    int p = 0, im = 0;

    for(int i = 0; i < n; i++){
        if(array[i] % 2 == 0){
            pares[p++] = array[i];
        } else{
            impares[im++] = array[i];
        }
    }

    selecaoCrescente(pares, p);
    selecaoDecrescente(impares, im);

    for(int i = 0; i < p; i++){
        printf("%d\n", pares[i]);
    }

    for(int i = 0; i < im; i++){
        printf("%d\n", impares[i]);
    }

    return 0;
}