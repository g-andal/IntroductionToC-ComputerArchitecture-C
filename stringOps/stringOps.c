#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printVowels(char*);

int main(int argc, char *argv[]){
    int i = 1;
	while(argv[i] != NULL)  
	{
        printVowels(argv[i]);
        i++;
	}
    printf("\n");
    return 0;
}

void printVowels(char* word){
    for(int i=0; i < strlen(word); i++){
        char letter = word[i];
        switch(letter){
            case 'a':
                printf("%c", letter);
                break;
            case 'e':
                printf("%c", letter);
                break;
            case 'i':
                printf("%c", letter);
                break;
            case 'o':
                printf("%c", letter);
                break;
            case 'u':
                printf("%c", letter);
                break;
            case 'A':
                printf("%c", letter);
                break;
            case 'E':
                printf("%c", letter);
                break;
            case 'I':
                printf("%c", letter);
                break;
            case 'O':
                printf("%c", letter);
                break;
            case 'U':
                printf("%c", letter);
                break;
        }
    }
}