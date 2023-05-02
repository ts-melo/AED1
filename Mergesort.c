#include <stdio.h>
#include <stdlib.h>

void generate(int v[], int n){
    int i;
    for(i = 0; i < n; i++){
        v[i] = rand() % 1000;
    }
}

void merge(int v[], int l, int m, int r){
    int *aux = malloc(sizeof(int)*(r-l)); // alocando um espaço de memoria temporário
    int i=l, j=m+1, k=0; // j=m+1 pq vai varrer a metade direita
    while(i <= m && j <= r){ // vai comparando e intercalando até acabar um dos sub-vetores
        if(v[i] <= v[j]){
            aux[k++]= v[i++];
        }else aux[k++] = v[j];
    }

    // esses dois proximos laços serão executados caso um sub-vetor se esgote antes do outro,
    // então vai usar o que sobrou para completar
    /*
    ex: se o vetor da direita(i....m) for maior que o da esquerda(j...r), quando o da esquerda acabar, mas sobrarem itens no da direita, 
    o vetor q estamos formando(aux[k]) sera completado com o que resta do sub-vetor da direita
    */
    while(i <= m){
        aux[k++] = v[i++];
    }
    while(j <= r){
        aux[k++] = v[j];
    }
    // colocando os itens agora organizados do vetor temporário(aux[]) no vetor original(v[])
    for(int t = l; t <= r; t++){
        v[t] = aux[t-l]; // usa t-l pq o vetor aux n necessariamente começa do 0
    }
}

int mergesort(int v[], int l, int r){
    if(l<r){ // só entra quando o vetor n pode mais ser dividido (tem só uma posição)
        int m = (r+l)/2; // acha o meio
        mergesort(v, l, m); //chamada recursiva para o lado esquerdo (não sai daqui até completar todo o lado esquerdo)
        mergesort(v, m+1, r);//chamada recursiva para todo o lado direito
        merge(v, l, m, r);// intercala os sub-vetores agr ordedados 
    }
}

int main(void){
    int v[20000], n=5000;
    generate(v, n);
    mergesort(v, 0, n-1);
    return 0;
}