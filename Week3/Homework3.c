// HW #03, Nolan Stutelberg
#include <stdio.h>

/**
 * Homework Info:
 *
 * I renamed the function names to not use numbers in them, and to use camel case. I generally only use pascal case with classes, and find using numbers in functions/methods is not as clear.
 * I also renamed the parameter names and the initialized variables in the main function to keep consistency between all the functions, and to give more traceability in the code
 * You can expand or collapse the extra long comments. I wanted to keep them so I can look back on my homework and re-read my thought process
 */

// Declaring function prototypes. Address variables are needed for the first two functions because these functions will ahve their values read and modified in the main function
// The printValues function is just being called in the main function directly, so a pointer is not needed
int getInteger(int *pInputInt);
int getTwoFloatingValues(float *pInputFloat, double *pInputDouble);
int printValues(int inputInt, float inputFloat, double inputDouble);

int main(void)
{
    printf("HW #03, Nolan Stutelberg\n\n");
    int inputInt;
    float inputFloat;
    double inputDouble;

    /**
     * Pointer explanation for me only...
     *
     * The `&` is accessing the addresses of the variables, so when the helper function scans in the data and has the `*` to use the address, then in the helper, the memory address
     * gets populated with the value of what was scanned. So after calling the `getInteger` and `getTwoFloatingValues` functions, lines 21 to 23 will have values in their addresses
     * and they can be accessed normally with no pointer.
     * The use of `int getInteger(int *inputInt)` function is to place the scanned integer value at the address of *inputInt, and then you use `&inputInt` to point to that memory location.
     * After the `getInteger` function is called, if you printed `&inputInt` it would return an address (random collection of letters and numbers). If after you call the function, you printed `inputInt`,
     * then the actual value would be printed, since earlier in the code, we pointed to the memory location with `&inputInt`, so within the scope of the function, C remembers what the address is, and what value
     * is stored at that address. When you call inputInt, C will try to pull the value from that address. But say you called inputInt after it was initialized but before running through the `getInteger` function,
     * you would get some random numbers that were chilling in the memory location already, and you would not get the actual value that you want.
     * `&inputInt` is the actual memory address hash value, so you have to use the pointer in the function call, because if you just did `inputInt`, it would be an empty initialized variable.
     * When you use the pointer in main with the function call `getInteger(&inputInt);`, this is the first and only time you need to use the pointer from within the scope of the main function. Since the `getInteger()`
     * function is assigning the scanned integer value to the memory location of inputInt, you need to do &inputInt for C to know what value is stored at that address, then you can use inputInt without pointers thereafter
     */

    int intReadFlag = getInteger(&inputInt);
    int floatReadFlag = getTwoFloatingValues(&inputFloat, &inputDouble);

    printf("The user entered %d integer(s) and %d floating point number(s)\n", intReadFlag, floatReadFlag);
    printf("The user entered: ");
    printValues(inputInt, inputFloat, inputDouble);
    printf("\nBye! Caio");

    return 0;
}

int getInteger(int *pInputInt)
{
    printf("Please enter an integer value -> ");

    /**
     * Since the parameter declaration used the address operator (*), this scanf is modifying the value of inputInt at its memory location. So then you can use &inputInt later to point to that memory location. And when you point to
     * that location later, there should be the integer value there, but C will print the actual address, and not the value. To access the actual value in the main function, you have to first point to the memory location, then
     * you can access the value freely just by calling the variable name. Since the indirection operator is used, this scanf is modifying the value of inputInt at its memory location. So then you can use &inputInt later to point
     *  to that memory location. The parameter `int *pInputInt` is saying that the function requires a memory address as an input argument when you call the function, or else you will get a mismatched type if you try to pass an actual value into this function
     */
    int result = scanf("%d", pInputInt);
    return result;
}

int getTwoFloatingValues(float *pInputFloat, double *pInputDouble)
{
    printf("Please enter two floating point numbers -> ");

    // Reading in one value as a float and storing it as a float, and reading in the other value as a double and storing it as a double for consistency
    // Don't need a pointer because the input parameter specifies that the argument will be an address,and not a value. So the scanf function will apply the value right to the address of the variable
    int result = scanf("%f %lf", pInputFloat, pInputDouble);
    return result;
}

int printValues(int inputInt, float inputFloat, double inputDouble)
{
    // No address variables are needed here because the variables will not be modified anywhere in the program
    printf("%d, %g, %g", inputInt, inputFloat, inputDouble);
    return 0;
}

/*

HW #03, Nolan Stutelberg

Please enter an integer value -> 1234
Please enter two floating point numbers -> 0.000000432 9.23e8
The user entered 1 integer(s) and 2 floating point number(s)
The user entered: 1234, 4.32e-07, 9.23e+08
Bye! Caio

*/