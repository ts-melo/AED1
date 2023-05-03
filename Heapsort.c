#include <stdio.h>
#include <stdlib.h>

// heap = binarytree-based data structure -> complete binary tree where all fathers are greater than their children(in a max heap) and every parent has max 
// parent i -> children 2*i+1 and 2*i+2
// children's index is f -> parent's index is 1/2 f  

  
void generate(int v[], int n){
    for(int i = 1; i < n; i++){
        v[i] = rand()%100;
    }
}

void incert(int v[], int n){
    int f = n+1,t;
    while(f>1 && v[f/2] < v[f]){
        t = v[f/2]; v[f/2] = v[f]; v[f] = t;
        f = f/2;
    }
}

void heapify(int v[], int n){
    int f=2, t;
    while(f<=n){
        if(f<n && v[f]< v[f+1]) ++f;
        if(v[f/2] >= v[f]) break;
        t = v[f/2]; v[f/2] = v[f]; v[f] = t;
        f *= 2;
    }
}

void Heapsort(int v[], int n){
    int m,t;
    for(m = 1; m < n; m++){
        incert(v,n);
    }
    for(m = n; m > 1; m--){
        t = v[1]; v[1] = v[m]; v[m] = t;
        heapify(v, m-1);
    }
}

int main(){
    int v[20000], n=20000; 
    generate(v,n);
    Heapsort(v,n);
    return 0;
}