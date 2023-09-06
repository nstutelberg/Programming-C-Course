// questions - check the reading in of the float values. do i read in the float and have implicit conversion convert it to double? or do i keep the data types consistent?

// HW #03, Nolan Stutelberg
#include <stdio.h>

/**
 * I renamed the function names to not use numbers in them, and to use camel case. I generally only use pascal case with classes, and find using numbers in functions/methods is not as clear.
 */

// Declaring function prototypes. Address variables are needed for the first two functions because these functions will ahve their values read and modified in the main function
// The printValues function is just being called in the main function directly, so a pointer is not needed

int getInteger(int *pNum);
int getTwoFloatingValues(float *pfVal, double *pdVal);
int printValues(int iNum, float fVal, double dVal);

int main(void)
{
    printf("HW #03, Nolan Stutelberg\n\n");
    int inputInt;
    float inputFloat;
    double inputDouble;

    // Use pointers here because we are modifying the variables by assigning them to new variables
    int intReadFlag = getInteger(&inputInt);
    int floatReadFlag = getTwoFloatingValues(&inputFloat, &inputDouble);

    printf("The user entered %d integer(s) and %d floating point number(s)\n", intReadFlag, floatReadFlag);
    printf("The user entered: ");
    printValues(inputInt, inputFloat, inputDouble);
    printf("\nbye");

    return 0;
}

int getInteger(int *pNum)
{
    printf("Please enter an integer value -> ");

    // Since the parameter declaration used the address operator (*), the variable is storing the address, not the value, so calling it will call it's address in memory. So no need to use a pointer
    int result = scanf("%d", pNum);
    return result;
}

int getTwoFloatingValues(float *pfVal, double *pdVal)
{
    printf("Please enter two floating point numbers -> ");
    int result = scanf("%f %lf", pfVal, pdVal);
    return result;
}

int printValues(int iNum, float fVal, double dVal)
{
    printf("%d, %g, %g", iNum, fVal, dVal);
    return 0;
}