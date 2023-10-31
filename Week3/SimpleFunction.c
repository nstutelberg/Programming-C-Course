#include <stdio.h>
// declare the prototype
double multiply(double multiplier, double multiplicand);

// notice how no pointers are needed since there is only one return value and not two
// this is an example of passing by value, because we didn't return any addresses here. If the only thing that is being used in main is the return value from the function, then you don't need to 
// use a pointer.

int main(void)
{
    double product;

    product = multiply(6, 7);
    printf("%lf", product);

    return 0;
}

double multiply(double x, double y)
{
    return x * y;
}