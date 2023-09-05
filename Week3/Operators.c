/**
 * Modulus operator
 *
 * Used in integer arithmetic. It gives the raminder that results when the integers are divided
 * Ex: if you did 13 % 5, you would get 3
 */
#include <stdio.h>
int main(void)
{
    float numResult;
    numResult = 13 % 5;
    printf("%f", numResult);

    // modulo is mostly used to see if something is even as well
    printf("\n");
    int evenNum;
    evenNum = 40;
    if (evenNum % 2 == 0)
    {
        printf("%d is even.\n", evenNum);
    }
    else
    {
        printf("%d is odd.\n", evenNum);
    }

    return 0;
}

/**
 * increment and decrement operators
 *
 * ++i means increment i and then use its new value
 * i++ means use the current value of i, then increment it
 * if you have y = x++ * 2, then if x is 3, the result will be 6 since the value is incremented at the end
 * if you do y = ++x * 2, and x is 3, then result will be 8, because i gets incremented FIRST, then it is used in the operation
 *
 */