// questions - check the reading in of the float values. do i read in the float and have implicit conversion convert it to double? or do i keep the data types consistent?

// HW #03, Nolan Stutelberg
#include <stdio.h>

/**
 * I renamed the function names to not use numbers in them, and to use camel case. I generally only use pascal case with classes, and find using numbers in functions/methods is not as clear.
 * I also renamed the parameter names and the initialized variables in the main function to keep consistency between all the functions, and to give more traceability in the code
 */

// Declaring function prototypes. Address variables are needed for the first two functions because these functions will ahve their values read and modified in the main function
// The printValues function is just being called in the main function directly, so a pointer is not needed

int getInteger(int *inputInt);
int getTwoFloatingValues(float *inputFloat, double *inputDouble);
int printValues(int inputInt, float inputFloat, double inputDouble);

int main(void)
{
    printf("HW #03, Nolan Stutelberg\n\n");
    int inputInt;
    float inputFloat;
    double inputDouble;

    /**
     * The `&` is accessing the addresses of the variables, so when the helper function scans in the data and has the `*` to use the address, then the variables are assigned the value of what was scanned.
     * So after these 2 below lines, lines 21 to 23 will have values in their addresses and they can be accessed normally with no pointer.
     * The use of `int getInteger(int *inputInt)` is to place the scanned integer value at the address of *inputInt, and the use of `&inputInt` is to point to the value at the address
     * This way, C knows that when you call inputInt, that there is a value tied to it. Since when you initialize the variable, the type is known, but the address is empty
     *  `&inputInt` is the actual memory address hash value, so you have to use the pointer in the function call, because if you just did `inputInt`, it would be an empty initialized variable
     * When you use the pointer here, you are saying that in the `getInteger` function, that the value at the address location will be modified
     * `*` is used to access the value stored at a memory address (when used with a pointer) - `&` is used to obtain the memory address of a variable.
     */
    printf("test 1: %p", &inputInt);
    printf("test 2: %d", inputInt);
    int intReadFlag = getInteger(&inputInt);
    int floatReadFlag = getTwoFloatingValues(&inputFloat, &inputDouble);

    printf("test 3: %d", inputInt);
    printf("test 4: %p", &inputInt);

    printf("The user entered %d integer(s) and %d floating point number(s)\n", intReadFlag, floatReadFlag);
    printf("The user entered: ");
    printValues(inputInt, inputFloat, inputDouble);
    printf("\nBye! Caio");

    return 0;
}

int getInteger(int *inputInt)
{
    printf("Please enter an integer value -> ");

    // Since the parameter declaration used the address operator (*), this scanf is modifying the value of inputInt at its memory location. So then you can use &inputInt later to point to that memory location.
    // And when you point to that location later, there should be the integer value there, but C will print the actual address, and not the value.
    // And to access the actual value in the main function, you have to first point to the memory location, then you can access the value freely without a pointer
    *inputInt = 10;
    return 0;
}

int getTwoFloatingValues(float *inputFloat, double *inputDouble)
{
    printf("Please enter two floating point numbers -> ");

    // Reading in one value as a float and storing it as a float, and reading in the other value as a double and storing it as a double for consistency
    int result = scanf("%f %lf", inputFloat, inputDouble);
    return result;
}

int printValues(int inputInt, float inputFloat, double inputDouble)
{
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