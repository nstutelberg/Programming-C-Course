#include <stdio.h>
// declare the prototype
double multiply(double multiplier, double multiplicand);

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