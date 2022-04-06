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
    int num[length];
    int index = 0;

    // read second line (all of the elements)
    fgets(str, 20, fp);
    str[strcspn(str, "\n")] = 0;  // removes newline
	
    int init_size = strlen(str);
	char delim[] = " ";

	char *ptr = strtok(str, delim);

	while(ptr != NULL)      // while loop to break string apart at spaces
	{
        // puts every element into num
		int new_num = atoi(ptr);
        num[index] = new_num;
        index++;

		ptr = strtok(NULL, delim);
	}

    // loop to print out elements in num
	for (int i = 0; i < length; i++)
	{
		printf("%d ", num[i]);
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