#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[] )  {
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

    

    // while (fgets(str, MAX_LENGTH, fp))
    //     printf("%s", str);

//    if( argc == 2 ) {
//       printf("The argument supplied is %s\n", argv[1]);
//    }
//    else if( argc > 2 ) {
//       printf("Too many arguments supplied.\n");
//    }
//    else {
//       printf("One argument expected.\n");
//    }

}