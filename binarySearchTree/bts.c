#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(int);
Node* insert(Node*, int);
void printTree(Node*);
int search(Node*, int);

Node* root = NULL;

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("error\n");
        return 1;
    }

    char instr; // i: insert; s: search
    int num;    // value to add or search for

    while(!feof(fp)){
        fscanf(fp, "%c\t%d\n", &instr, &num);
        if (instr == 'i'){
            if(root == NULL){
                root = newNode(num);
            }
            else if(search(root, num)){
                insert(root, num);
            }
        }
    }

    printTree(root);
    printf("\n");

    return 0;
}

Node* newNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* cur, int data){
    if(cur==NULL){
        return newNode(data);
    }
    else if(data>cur->data){
        cur->right = insert(cur->right, data);
    }
    else if(data<cur->data){
        cur->left = insert(cur->left, data);
    }
    return cur; 
}

int search(Node* cur, int data){
    if(cur==NULL){
        return 1;
    }
    else if(data>cur->data){
        return search(cur->right, data);
    }
    else if(data<cur->data){
        return search(cur->left, data);
    }
    return 0; 
}

void printTree(Node* cur){
    if (cur != NULL) {
        printTree(cur->left);
        printf("%d\t", cur->data);
        printTree(cur->right);
        free(cur);
    }
}
