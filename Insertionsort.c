#include <stdio.h>
#include <stdlib.h>

void generate(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i]= rand()%1000;
    }
}

int insertsort(int v[], int n){
    int aux, i, j;
    for(i = 1; i < n; i++){
        aux = v[i-1]; //valor anterior ao q to pegando pra comparar;
        for(j = i-1; j >= 0 && v[j] > aux; j--){ // caso seja maior, será movido para a direita
            v[j+1] = v[j];
        }
        v[j+1] = aux; // se o numero q to comparando for menor q o meu aux, deixo ele lá e coloco o aux na posição seguinte
    }
}


int main (){
    int v[20000], n=20000;
    generate(v, n);
    insertsort(v,n);
    return 0;
}