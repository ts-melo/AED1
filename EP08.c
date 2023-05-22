#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct node{
    char data;
    struct node *left;
    struct node *right;
}node;

node* createnode(char data){
    node *nono = malloc(sizeof(node));
    nono->data = data;
    nono->left = NULL;
    nono->right = NULL;
    return nono;
}

node* insert(node*root, char data){ // I
    if (root == NULL){
        root = createnode(data);
    }else if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

void readpos(node*root){
    if(root == NULL) return;
    readpos(root->left);
    readpos(root->right);
    printf("%c", root->data);
}

void readpre(node*root){
    if(root == NULL) return;
    printf("%c", root->data);
    readpre(root->left);
    readpre(root->right);
}

void readinf(node*root){
    if(root == NULL) return;
    readinf(root->left);
    printf("%c", root->data);
    readinf(root->right);
}

int find(node*root, char data){
    if(root == NULL){
        return 0;
    } else if (root->data == data){
        return 1;
    }else if (root->data < data){
        return find(root->right, data);
    }else if(root->data > data){
        return find(root->left, data);
    }
    return 0;
}

int main(){
    node* root = NULL;
    char faz[10], data;

    while( scanf(" %s", faz) != EOF){
        if(strcmp(faz, "I") == 0){
            scanf(" %c", &data);
            root = insert(root, data);
        }else if(strcmp(faz, "INFIXA") == 0){
            printf("\n");
            readinf(root);
            printf("\n");
        }else if(strcmp(faz, "PREFIXA") == 0){
            readpre(root);
            printf("\n");
        }else if(strcmp(faz, "POSFIXA") == 0){
            readpos(root);
            printf("\n");
        }else if(strcmp(faz, "P") == 0){
            scanf(" %c", &data);
            if(find(root,data)) 
                printf("%c existe\n", data);
            else 
                printf("%c nao existe\n", data);
        }
    }
    return 0;
}
