#include <stdio.h>

char *stringReturner(char *myString)
{
    return myString;
}

int main(void)
{
    char *finalOutput;
    finalOutput = stringReturner("hello");
    printf("%s\n", finalOutput);
    return 0;
}
