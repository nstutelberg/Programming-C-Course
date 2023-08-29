// HW #02, Nolan Stutelberg
#include <stdio.h>

int main(void)
{
    printf("HW #02, Nolan Stutelberg\n\n");
    printf("Enter the number of cups to be converted ->");

    // Scanf uses the pointer because you need the memory address of where the input should be stored
    double userCupValue;
    scanf("%lf", &userCupValue);

    // Set all the variables as doubles to retain the decimal places
    double pint = userCupValue / 2.0;
    double oz = userCupValue * 8.0;
    double tblspoon = oz * 2.0;
    double teaspoon = tblspoon * 3.0;

    printf("\nYour value of %.3lf cups is equivalent to...\n", userCupValue);
    printf("Pints:          %.3lf\n", pint);
    printf("Ounces:        %.3lf\n", oz);
    printf("Tablespoons:   %.3lf\n", tblspoon);
    printf("Teaspoons:    %.3lf\n", teaspoon);

    return 0;
}

/*

HW #02, Nolan Stutelberg

Enter the number of cups to be converted ->
3.2
Your value of 3.200 cups is equivalent to...
Pints:          1.600
Ounces:        25.600
Tablespoons:   51.200
Teaspoons:    153.600

*/
