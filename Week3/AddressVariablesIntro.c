#include <stdio.h>
#include <string.h>

/**
 * Need to use `*` because you are using a pointer delcaration to declare a pointer variable to create a variable that can store memory addresses
 * The * operator is used for dereferencing pointers. When you place * before a pointer variable, it allows you to access the value stored at the memory address pointed to by that pointer.
 * The & operator is used to obtain the memory address of a variable. When you place & before a variable, it returns a pointer to the memory location where that variable is stored.
 * * is for declaring that the variable needs a pointer, and & is for accessing the value using the pointer
 * int *myNum = &x;     // myNum stores the address of x, obtained using &
 */

char *stringReturner(char *myString)
{
    strcat(myString, " how are you?");
    return myString;
}

int main(void)
{
    char helloString[50] = "hello";
    char *finalOutput = stringReturner(helloString);
    printf("%s\n", finalOutput);
    return 0;
}
