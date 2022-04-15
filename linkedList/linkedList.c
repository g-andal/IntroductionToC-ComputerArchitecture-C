#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node *head = NULL;
struct node *current = NULL;

void insert(int);
void delete(int);

int main(int argc, char *argv[] )  {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("error\n");
        return 1;
    }

    char instr; // i: insert; d: delete
    int num;    // value to add or delete

    while(!feof(fp)){
        fscanf(fp, "%c\t%d\n", &instr, &num);
        if (instr == 'i'){
            printf("going into insert\n");
            insert(num);
            printf("succesful insert of %d\n", num);
        }
        else{
            printf("going into delete\n");
            delete(num);
            printf("succesful delete of %d\n", num);
        }
    }

    fclose(fp);
    return 0;
}

struct node {
   int data;
   struct node *next;
};

void insert(int data) {
    if(head == NULL || head->data >= data){
        struct node *new = (struct node*) malloc(sizeof(struct node));
	    new->data = data;
        new->next = head;
        head = new;
        current = head;
        return;
    }

    while(true){
        if(current->next == NULL || current->next->data >= data){
            struct node *new = (struct node*) malloc(sizeof(struct node));
	        new->data = data;
            new->next = current->next;
            current->next = new;
            break;
        }
        current = current->next;
    }
    current = head;
}

void delete(int data) {
    if(head == NULL || head->data > data){
        return;
    }

    if(head->data == data){
        head = head->next;
        current = head;
        return;
    }

    while(current->next!= NULL){
        if(current->next->data == data){
            current->next = current->next->next;
            break;
        }
        current = current->next;
    }

    current = head;
}





