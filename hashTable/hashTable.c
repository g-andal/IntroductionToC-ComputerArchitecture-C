#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

int hashCode(int);
void init_table();
bool search(int);
void insert(int);
void freeTable();

typedef struct Node{
   int data;   
   struct Node* next;
}Node;

typedef struct{
    int num_of_items;
    Node** table_entries;
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
    init_table();

    while(!feof(fp)){
        fscanf(fp, "%c\t%d\n", &instr, &num);
        if (instr == 'i'){
            insert(num);
        }
        else{
            search(num);
        }
    }


    printf("%d\n", inserts);
    printf("%d\n", searches);
    freeTable();

    fclose(fp);
    return 0;

}

int hashCode(int key) {
   int code = key % MAX_SIZE;
   if (code < 0){
       code += 1000;
   }
   return code;
}

void init_table(){
    table.table_entries = malloc(sizeof(Node*) * MAX_SIZE);
    table.num_of_items = 0;
	for (int i = 0; i < MAX_SIZE; i++){
		table.table_entries[i] = NULL;
	}
}

bool search(int data){
    Node* cur = table.table_entries[hashCode(data)];
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
        Node* head = table.table_entries[key];
        Node* temp = malloc(sizeof(Node));
        temp->data = data;
        temp->next = head;
        table.table_entries[key] = temp;

        if(head != NULL){
            inserts++;
        }
    }
}

void freeTable(){
    for(int i = 0; i < MAX_SIZE; i++){
        if (table.table_entries[i] != NULL){
            Node* head = table.table_entries[i];
            Node* temp = head->next;
            free(head);
            while(temp != NULL){
                head = temp;
                temp = temp->next;
                free(head);
            }
        }
    }
}