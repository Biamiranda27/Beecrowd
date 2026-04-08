#include<stdio.h>

void swap(int[] array, int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
void selecao(int[] array, int n){
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

void insercao(int[] array, int n){
    int chave;
    for(int i = 1; i < n; i++){
        chave = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > chave){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = chave;
    }
}

void swap(int[] array, int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
void bubble(int[] array, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(array[j+1] < array[j]){
                swap(array, j, j+1);
            }
        }
    }
}

void insercao(int[] array){
    int chave;
    for(int i = 1; i < n; i++){
        chave = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > chave){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = chave;
    }

}