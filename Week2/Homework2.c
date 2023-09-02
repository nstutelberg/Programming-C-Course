// HW #02, Nolan Stutelberg
#include <stdio.h>

int main(void)
{
    printf("HW #02, Nolan Stutelberg\n\n");
    double userCupValue;
    int validInput = 0;

    /**
     * Continue prompting the user for a valid input value until one is returned, then exit the loop
     * The scan has to return a successful return code and the user input value must be less than 1,000,000. This is to keep the formatting consistent
     * Scanf uses the pointer because you need the memory address of where to store the user input. The variable was initialized and needs the pointer to have a value assigned to it
     * The end is clearing the input buffer. This deletes any extra lines or spaces so that the next user input starts from scratch. It reads and discards characters until a newline character is found
     * */

    while (validInput != 1)
    {
        printf("Enter the number of cups to be converted using a non-negative number with up to 2 decimal spaces (limit is 1000000) -> ");
        if (scanf("%lf", &userCupValue) == 1 && userCupValue < 1000000)
        {
            validInput = 1;
        }
        else
        {
            printf("\nInvalid input. We all know you don't have a million cups of flour anyway. ");
            while (getchar() != '\n')
                ;
        }
    }

    // Set all the conversion variables as doubles to retain the decimal places. Minimum width is 12, which will allow input values to be as high as 999,999.99
    double pint = userCupValue / 2.0;
    double oz = userCupValue * 8.0;
    double tblspoon = oz * 2.0;
    double teaspoon = tblspoon * 3.0;
    int spacingNum = 12;

    // Properly space all values so decimals and equal signs line up. Use spacingNum to set all the minimum widths. This accounts for higher input values while keeping consistency in format
    printf("%10.2lf cups = %*.3lf pints\n", userCupValue, spacingNum, pint);
    printf("                = %*.3lf ounces\n", spacingNum, oz);
    printf("                = %*.3lf tablespoons\n", spacingNum, tblspoon);
    printf("                = %*.3lf teaspoons\n", spacingNum, teaspoon);

    return 0;
}

/*

HW #02, Nolan Stutelberg

Enter the number of cups to be converted using a non-negative number with up to 2 decimal spaces (limit is 1000000) -> 1102102910921029

Invalid input. We all know you don't have a million cups of flour anyway. Enter the number of cups to be converted using a non-negative number with up to 2 decimal spaces (limit is 1000000) -> 3.20
      3.20 cups =        1.600 pints
                =       25.600 ounces
                =       51.200 tablespoons
                =      153.600 teaspoons

*/
