// HW #01, Nolan Stutelberg
#include <stdio.h>

int main()
{
    // Specify the input types that the user will enter
    char inputCharacter;
    int inputInteger;
    float inputFloat;

    printf("HW #01, Nolan Stutelberg\n");
    printf("Enter your input in this order with a space between each value: character integer floating-point-number: ");

    // Accept input, but use a pointer because C needs to be able to modify the original variable value that is stored in memory in order for the `printf` statements below to return the stored value
    scanf("%c %d %f", &inputCharacter, &inputInteger, &inputFloat);

    printf("%1c\n", inputCharacter);
    printf("%d\n", inputCharacter);
    printf("%d\n", inputInteger);
    printf("%f\n", inputFloat);
}

/*

HW #01, Nolan Stutelberg
Enter your input in this order with a space between each value: character integer floating-point-number: C 1111 3.14
C
67
1111
3.140000

*/
