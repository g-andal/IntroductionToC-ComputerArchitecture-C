#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node *head = NULL;
struct node *current = NULL;
int size = 0;

void insert(int);
void delete(int);
void printList();

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
            insert(num);
        }
        else{
            delete(num);
        }
    }
    printf("%d\n", size);
    if(head != NULL){
        printList();
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
        size++;
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
    size++;
}

void delete(int data) {
    if(head == NULL || head->data > data){
        return;
    }

    if(head->data == data){
        head = head->next;
        current = head;
        size--;
        return;
    }

    while(current->next!= NULL){
        if(current->next->data == data){
            current->next = current->next->next;
            size--;
            break;
        }
        current = current->next;
    }

    current = head;
}

void printList(){
    printf("%d\t", current->data);
    int lastPrinted = current->data;
    current = current->next;
    free(head);
    head = current;
    while(true){
        if(current->data != lastPrinted){
            printf("%d\t", current->data);
            lastPrinted = current->data;
        }

        if(current->next != NULL){
            current = current->next;
            free(head);
            head = current;
        }
        else{
            free(head);
            break;
        }
    }
    printf("\n");
}





