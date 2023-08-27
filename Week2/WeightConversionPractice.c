#include <stdio.h>

int main(void)
{

    // Getting weight in lbs
    printf("enter your weight in pounds as a double value");
    double weightLBS;
    scanf("%lf", &weightLBS);

    // Getting weight in oz
    double weightOZ;
    weightOZ = 16 * weightLBS;

    printf("weight in lbs is: %lf, and the weight in oz is: %lf", weightLBS, weightOZ);
    return 0;
}