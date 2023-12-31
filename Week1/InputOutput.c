// This file is used to read user input and store it as an array

#include <stdio.h>

// 10 length array that can contain only characters
char myArray[10];
char myArray2[10];

int main()
{
    // Have to use a passed value so when you type something in, then the scanf will store the value in the array. Note that the array is length 10, but c will let you put in as many values as you want
    printf("enter your string:");
    scanf("%s", myArray);
    printf("Your first array contains: %s\n", myArray);

    // If you want to limit the input to be only as large as the data structure holding it, you have to use a `10` right before the scanf
    printf("enter your second string that can not be larger than 10 chars:");
    scanf("%10s", myArray2);
    printf("Your second array contains: %s\n", myArray2);
}

// So now if you enter a 20 digit string, the first block will return the string in its entirety, but the second one will only return the first 10 characters that were typed