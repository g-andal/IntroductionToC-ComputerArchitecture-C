#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

int hashCode(int);
void init_table();
bool search(int);
void insert(int);

struct Node{
   int data;   
   struct Node* next;
};

typedef struct{
    int num_of_items;
    struct Node** table_entries;
}Hashtable;

Hashtable table;
int searches = 0;
int inserts = 0;

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
            insert(num);
        }
        else{
            search(num);
        }
    }

}

int hashCode(int key) {
   int code = key % MAX_SIZE;
   if (code < 0){
       code += 1000;
   }
   return code;
}

void init_table(){
    table.table_entries = malloc(sizeof(struct Node*) * MAX_SIZE);
    table.num_of_items = 0;
	for (int i = 0; i < MAX_SIZE; i++){
		table.table_entries[i] = NULL;
	}
}

bool search(int data){
    struct Node* cur = table.table_entries[hashCode(data)];
    while(cur != NULL){
        if(cur->data == data){
            searches++;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void insert(int data){
    int key = hashCode(data);
    if(!search(data)){
        struct Node* head = table.table_entries[key];
        struct Node* temp = malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = head;
        table.table_entries[key] = temp;

        inserts++;
    }
}