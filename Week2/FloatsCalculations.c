#include <stdio.h>

int main(void)
{
    // Testing mathematical operations using floats
    float x;
    float y;
    float z;

    x = 1 / 3;
    y = 1.0 / 3;
    z = 1.0 / 3.0;
    printf("the first float calculations returned: %f, %f, %f \n", x, y, z);

    // Testing now with integers
    int x2;
    int y2;
    int z2;

    x2 = 1 / 3;
    y2 = 1.0 / 3;
    z2 = 1.0 / 3.0;
    printf("the second float calculations returned: %f, %f, %f", x2, y2, z2);

    /**
     * Results:
     * x calculation returned 0 because it was integer division. When two numbers with no decimals are divided, C does integer division and returns only a whole number
     * y calculation resulted in the right value because the first value was a float, so it was floating point division (which returns values with decimals)
     * z calculation resulted in the right value because both values were floats, so it was floating point division
     *
     * x2,y2,z2 all returned zero because integers always round the numbers and the decimal is truncated
     */
}