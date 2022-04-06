#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(int [], int, int);

int main(int argc, char *argv[] )  {
    // open file
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    // create input string array
    char str[20];

    // read first line and create number array
    fgets(str, 20, fp);

    int length = atoi(str);
    int even[length];
    int odd[length];

    // read second line (all of the elements)
    fgets(str, 20, fp);
    str[strcspn(str, "\n")] = 0;  // removes newline
	
    int init_size = strlen(str);
	char delim[] = " ";

	char *ptr = strtok(str, delim);
    int new_num;
    int even_i = 0; // keeps track of latest index in even array
    int odd_i = 0;  // keeps track of latest index in odd array

	while(ptr != NULL)      // while loop to break string apart at spaces
	{
        // changes num from string to int
		new_num = atoi(ptr);

        // places number into respective array (even or odd)
        if(new_num % 2 == 0){
            even[even_i] = new_num;
            even_i++;
        }
        else{
            odd[odd_i] = new_num;
            odd_i++;
        }
        
		ptr = strtok(NULL, delim);
	}
   
   sort(even, 0, even_i - 1);
   sort(odd, 0, odd_i - 1);

    // print out even numbers
	for (int i = 0; i < even_i; i++)
	{
		printf("%d ", even[i]);
        
	}

    // print out odd numbers
    for (int i = 0; i < odd_i; i++)
	{
		printf("%d ", odd[i]);
	}
	printf("\n");

    // close the file
    fclose(fp);

    return 0;

}

// quick sort
void sort(int arr[], int low, int high){
    int pivot, value1, value2, temp;
    if (low < high){
        pivot = low;
        value1 = low;
        value2 = high;

        while (value1 < value2){
            while (arr[value1] <= arr[pivot] && value1 <= high){
                value1++;
            }
    
            while (arr[value2] > arr[pivot] && value2 >= low){
                value2--;
            }

            if (value1 < value2){
                temp = arr[value1];
                arr[value1] = arr[value2];
                arr[value2] = temp;
            }
        }
    
        temp = arr[value2];
        arr[value2] = arr[pivot];
        arr[pivot] = temp;

        sort(arr, low, value2 - 1);
        sort(arr, value2 + 1, high);
    }
}