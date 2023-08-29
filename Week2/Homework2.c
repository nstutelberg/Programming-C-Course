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

    // Properly space all values so decimals and equal signs line up, and put their
    printf("%.2lf cups  =    %.3lf pints\n", userCupValue, pint);
    printf("           =   %.3lf ounces\n", oz);
    printf("           =   %.3lf tablespoons\n", tblspoon);
    printf("           =  %.3lf teaspoons\n", teaspoon);

    return 0;
}

/*

HW #02, Nolan Stutelberg

Enter the number of cups to be converted ->3.2
3.20 cups  =    1.600 pints
           =   25.600 ounces
           =   51.200 tablespoons
           =  153.600 teaspoons

*/
