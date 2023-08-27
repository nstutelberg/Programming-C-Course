// First need to import the libraries using the syntax below. Note that standard I/O is not included in base C, you need to import it
#include <stdio.h>

// Need to use main as an entry point to the program, `int` is saying that the function is being used to return an integer value, which is usually an error code
// Void means that this function is not going to accept any arguments, and every thing that is in the function is alredy there
int main(void)
{
    int suppliedNum = 5;

    // If you want to add a new line you can do it within the string with `\n`
    printf("Hello, world!\nAre you good today?\n");

    // This is using an f string or a .format() string like in Python. You can include as many parameters as you want, and the other arguments are the values to be passed through
    printf("Hello my number is %d and the number again is %d", suppliedNum, suppliedNum);

    // This is the integer value that is being returned. Instead of an error code, we are just setting it to return 0
    return 0;
}