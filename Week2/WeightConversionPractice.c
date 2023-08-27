#include <stdio.h>

int main(void)
{

    // Getting weight in lbs
    printf("enter your weight in pounds as a double value");
    double weightLBS;
    scanf("%lf", &weightLBS);

    // Getting weight in oz
    double weightOZ;
    weightOZ = 16.0 * weightLBS;

    // Printing while specifying how many decimal places to include. 3 decimal places for lbs and 2 for oz
    // The number before the period is the minimum number of characters to the left of the decimal
    // The number after the period is the amount of digits to the right of the period. Not typing anything to left of period means there can be infinite numbers
    // If you set a limit of say 4 characters to left of period `%4.3f`, then c will add extra spaces to the left of the decimal to meet the minium number of spaces
    printf("weight in lbs is: %.3f lbs, and the weight in oz is: %.2f oz", weightLBS, weightOZ);
    return 0;
}