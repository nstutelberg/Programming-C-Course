// HW #01, Nolan Stutelberg
#include <stdio.h>

int main(void)
{

    char inputCharacter;
    int inputInteger;
    float inputFloat;

    printf("HW #01, Nolan Stutelberg\n\n");
    printf("Enter your input in this order with a space between each value: character integer floating-point-number: ");

    // Accept input, but use a pointer because C needs to be able to modify the original variable value that is stored in memory in order for the `printf` statements below to return the stored value
    // We are not using a pointer with a string or string array so this is acceptable (I hope)
    scanf("%c %d %f", &inputCharacter, &inputInteger, &inputFloat);

    // Limiting the length of the character to 1
    printf("%1c\n", inputCharacter);
    printf("%d\n", inputCharacter);
    printf("%d\n", inputInteger);
    printf("%f\n", inputFloat);

    return 0;
}

char stringReturner(myString)
{
    char myString2;
    myString2 = myString + "hello";
    return myString2;
}

/*

HW #01, Nolan Stutelberg

Enter your input in this order with a space between each value: character integer floating-point-number: C 1111 3.14
C
67
1111
3.140000

*/
