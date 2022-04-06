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
    int pivot, low_i, high_i, temp;

    // breaks recursion if low >= high
    if (low < high){
        pivot = low; // pivot will be first element
        low_i = low;
        high_i = high;

        // keep going until we've seen all the elements in this partition
        while (low_i < high_i){
            // low index will keep incrementing as long as each element < pivot
            while (arr[low_i] <= arr[pivot] && low_i <= high){
                low_i++;
            }

            // high index will keep decrementing as long as each element > pivot
            while (arr[high_i] > arr[pivot] && high_i >= low){
                high_i--;
            }
            
            // both high and low i aren't the same number then switch the values at those indeces
            if (low_i < high_i){
                temp = arr[low_i];
                arr[low_i] = arr[high_i];
                arr[high_i] = temp;
            }
        }
    
        // switch pivot and last element in the low section
        temp = arr[high_i];
        arr[high_i] = arr[pivot];
        arr[pivot] = temp;

        // sort low section and high section
        sort(arr, low, high_i - 1);
        sort(arr, high_i + 1, high);
    }
}