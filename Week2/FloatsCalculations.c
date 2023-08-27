#include <stdio.h>

int main(void)
{
    float x;
    float y;
    float z;

    x = 1 / 3;
    y = 1.0 / 3;
    z = 1.0 / 3.0;

    printf("the first float calculations returned: %f, %f, %f \n", x, y, z);

    int x2;
    int y2;
    int z2;

    x2 = 1 / 3;
    y2 = 1.0 / 3;
    z2 = 1.0 / 3.0;
    printf("the second float calculations returned: %f, %f, %f", x2, y2, z2);
}