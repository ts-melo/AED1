#include <stdio.h>
#include <stdlib.h>

void generate(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % 100;
    }
}

void selectionsort(int v[], int n){
    int aux, i, j, min;
    for(i = 0; i < n-1; i++){ // começa no primero item e vai até o penultimo
        min =i; // minimo começa com o index i
        for(j = i+1; j < n; j++){ // começa pelo proximo item e vai até o fim 
            if(v[j] < v[min]) min = j; // se o que eu achar for menor do que eu tinha como minimo, o minimo é trocado pelo index j
        }
        aux = v[i]; 
        v[i] = v[min];
        v[min] = aux;
        // vou colocar meu atual numero(antigo index do minimo) em um lugar temporario, 
        //colocar o novo valor minimo onde o antigo estava, e colocar o antigo no lugar em que o atual minimo estava. só troca-los de lugar
    }
}

int main(){
    int v[20000], n=10000;
    generate(v, n);
    selectionsort(v, n);
    return 0;
}