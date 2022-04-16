#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

int hashCode(int);
void init_table();
bool searchList(int);

typedef struct{
   int data;   
   struct Node* next;
}Node;

typedef struct{
    int num_of_items;
    Node** table_entries;
}Hashtable;

Hashtable table;

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

bool searchList(int data){
    Node* cur = table.table_entries[hashCode(data)];
    while(cur != NULL){
        if(cur->data == data){
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void insertFirst(int data){
    int key = hashCode(data);
    if(!searchList(data)){
        Node* head = table.table_entries[key];
        Node* temp = malloc(sizeof(Node));
        temp->data = data;
        temp->next = head;
        table.table_entries[key] = temp;
    }
}

int main(){

}