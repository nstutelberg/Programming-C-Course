#include <stdio.h>
#include <ctype.h>

//basic program to read user input and see if something is a digit or a character
int main(void) {
    char inputChar;
    printf("enter a character or a digit -> ");
    scanf("%c", &inputChar);

    int isInt = isdigit(inputChar);

    if (isInt == 1) {
        printf("this character is a digit");
    } else {
        printf("this character is not a digit: %c\n", inputChar);
    }


}