// HW #02, Nolan Stutelberg
#include <stdio.h>

int main(void)
{
    printf("HW #02, Nolan Stutelberg\n\n");
    printf("Enter the number of cups to be converted ->");
    double userCupValue;

    // Scanf uses the pointer because you need the memory address of where the input should be stored
    scanf("%lf", &userCupValue);

    // Set all the variables as doubles to retain the decimal places
    double pint = userCupValue / 2.0;
    double oz = userCupValue * 8.0;
    double tblspoon = oz * 2.0;
    double teaspoon = tblspoon * 3.0;

    int myNum = 10;

    // Properly space all values so decimals and equal signs line up, and put their
    printf("%1.2lf cups  = \n", userCupValue);
    printf("           = %*.3lf pints\n", myNum, pint);
    printf("           = %*.3lf ounces\n", myNum, oz);
    printf("           = %*.3lf tablespoons\n", myNum, tblspoon);
    printf("           = %*.3lf teaspoons\n", myNum, teaspoon);

    return 0;
}