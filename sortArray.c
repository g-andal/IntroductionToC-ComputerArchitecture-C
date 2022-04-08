#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* readfile(char*, int*, int*, int*);
int* getNum(char [], int, int*, int*);
int* splitNums(int*, int, int, int);
void print(int*, int, int*, int);
void sort(int [], int, int);

int main(int argc, char *argv[] )  {
    int num_size=0, even_size=0, odd_size=0;
    int* nums = readfile(argv[1], &num_size, &even_size, &odd_size);

    int* even_nums = splitNums(nums, 0, num_size, even_size);
    int* odd_nums = splitNums(nums, 1, num_size, odd_size);

    sort(even_nums, 0, even_size - 1);
    sort(odd_nums, 0, odd_size - 1);

    print(even_nums, even_size, odd_nums, odd_size);

    free(nums);
    free(even_nums);
    free(odd_nums);

    return 0;

}

// read file and return int array of all numbers
int* readfile(char* file, int* arrsize, int* even, int* odd){
    // open file
    char *filename = file;
    FILE *fp = fopen(filename, "r");

    // create input string array
    char str[50];

    // read first line and create number array
    fgets(str, 50, fp);

    *arrsize = atoi(str);

    // read second line (all of the elements)
    fgets(str, 50, fp);
    str[strcspn(str, "\n")] = 0;  // removes newline
	
    // close the file
    fclose(fp);

    return getNum(str, *arrsize, even, odd);
}

// creates int array from string
int* getNum(char str[], int size, int* even, int* odd){
    int* numlist = malloc(sizeof(int)*size);
    int index = 0;
    
    char delim[] = "\t";
	char *ptr = strtok(str, delim);

    int new_num;
    
	while(ptr != NULL)      // while loop to break string apart at spaces
	{
        // changes num from string to int
		new_num = atoi(ptr);
        numlist[index] = new_num;
        index++;

        if(new_num % 2 == 0){
            *even += 1;
        }
        else{
            *odd += 1;
        }

		ptr = strtok(NULL, delim);
	}

    return numlist;
}

// returns array of only even or only odd numbers
int* splitNums(int* arr, int rem, int oldsize, int newsize){
    int* newArr = malloc(sizeof(int)*newsize);
    int curIndex = 0;
    
    for(int i = 0; i < oldsize; i++){
        if (rem == 0 && arr[i] % 2 == 0){
            newArr[curIndex] = arr[i];
            curIndex++;
        }
        else if(rem == 1 && arr[i] % 2 != 0){
            newArr[curIndex] = arr[i];
            curIndex++;
        }
    }
    return newArr;    
}

// print out the arrays
void print(int* even, int even_i, int* odd, int odd_i){
    // print out even numbers
	for (int i = 0; i < even_i; i++)
	{
		printf("%d\t", even[i]);
	}

    // print out odd numbers
    for (int i = odd_i-1; i >= 0; i--)
	{
		printf("%d\t", odd[i]);
	}
	printf("\n");
}

// quick sort
void sort(int* arr, int low, int high){
    int pivot, low_i, high_i, temp;

    // breaks recursion if low >= high
    if (low < high){
        pivot = low; // pivot will be first element
        low_i = low;
        high_i = high;
   
        // keep going until we've seen all the elements in this partition
        while (low_i < high_i){
            
            // low index will keep incrementing as long as each element < pivot
            while (arr[low_i] <= arr[pivot] && low_i <= high_i){
                low_i++;
            }

            // high index will keep decrementing as long as each element > pivot
            while (arr[high_i] > arr[pivot] && high_i >= low_i){
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