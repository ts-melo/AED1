#include <stdio.h>
#include <stdlib.h>

void generate(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = rand()%100;
    }
}

int split(int v[], int l, int r){ // separa o vetor e retorna a posição j do pivot
    int p, j=l, k, aux; // j recebe a primeira posição de início, para ir colocando os valores menores antes do pivot
    p = v[r]; //pivot recebe o ultimo valor (por conveniencia msm);
    for(k = l; k < r; k++){ // k vai varrendo todo o vetor
        if(v[k] <= p){ // caso encontrar um numero menor q o meu pivot, ele vai para onde o j estava( posições la no inicio do vetor) e v[j] vai pra posição k
            aux = v[j];
            v[j] = v[k];
            v[k] = aux;
            j++; // incrementar o j para q quando denovo achar um valor q seja menor q o pivot, ele ir para a posição do lado
        }
    }
    v[r] = v[j], v[j] = p;
    return j;
}

void Quicksort(int v[], int l, int r){
    int j;
    if (l<r){
        j = split(v,l,r);
        Quicksort(v,l,j);
        Quicksort(v, j+1,r);
    }
}

int main(){
    int v[20000], n=5000;
    generate(v,n);
    Quicksort(v,0,n);
    return 0;
}

