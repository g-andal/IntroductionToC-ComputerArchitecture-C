#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node *head = NULL;
struct node *current = NULL;

int main(int argc, char *argv[] )  {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("error\n");
        return 1;
    }

    char instr; // i: insert; d: delete
    int num;    // value to add or delete

    while(fscanf(fp, "%c\t%d", &instr, &num) != 0){
        
    }

    fclose(fp);
    return 0;
}

struct node {
   int data;
   struct node *next;
};

//insert link at the first location
void insertFirst(int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}






