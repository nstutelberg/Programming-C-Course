// HW #04, Nolan Stutelberg
#include <stdio.h>
#include <ctype.h>

// Declaring function prototypes
void ifElseFunction(char charVal);
void switchFunction(char charVal);

int main(void)
{
    printf("HW #04, Nolan Stutelberg\n\n");

    // Get user input value
    char userInputChar;
    printf("Enter a digit or a character -> ");
    scanf("%c", &userInputChar);

    ifElseFunction(userInputChar);
    switchFunction(userInputChar);

    return 0;
}

void ifElseFunction(char charVal)
{
    printf("\nExecuting the If/Else function...\n");
    printf("Using the user char input of: %c", charVal);

    if (isdigit(charVal)) {
        charVal += 32;
    } else if (islower(charVal) && charVal != 'a') {
        charVal = toupper(charVal);
    } else if (isupper(charVal) && charVal != 'A') {
        charVal = tolower(charVal);
    }

    printf("\nThe resulting value is: %c\n", charVal);

    return;

}


void switchFunction(char charVal) {

    printf("\nExecuting the Switch function...\n");
    printf("Using the user char input of: %c\n", charVal);

    // Generate a variable to determine which case to execute
    int caseNum = 0;
    if (isdigit(charVal)) {
        caseNum = 1;
    } else if (islower(charVal) && charVal != 'a') {
        caseNum = 2;
    } else if (isupper(charVal) && charVal != 'A') {
        caseNum = 3;
    }

    // Use the above variable to lay out multiple cases, depending on what value of caseNum is a match
    switch (caseNum) {
        case 1:
            charVal += 32;
            break;
        case 2:
            charVal = toupper(charVal);
            break;
        case 3:
            charVal = tolower(charVal);
            break;
        default:
            // No action needed
            break;
    }

    printf("The resulting value is: %c\n", charVal);

    return;
}

/*
Letter
    HW #04, Nolan Stutelberg

    Enter a digit or a character -> q

    Executing the If/Else function...
    Using the user char input of: q
    The resulting value is: Q

    Executing the Switch function...
    Using the user char input of: q
    The resulting value is: Q

Digit
    HW #04, Nolan Stutelberg

    Enter a digit or a character -> 8

    Executing the If/Else function...
    Using the user char input of: 8
    The resulting value is: X

    Executing the Switch function...
    Using the user char input of: 8
    The resulting value is: X

*/

/*

Test Plan:

Test 1: Enter a lowercase letter other than 'a'
   - Verify that it correctly converts the letter to uppercase
   - Result: Success, makes the letter uppercase

Test 2: Enter an uppercase letter other than 'A'
   - Verify that it correctly converts the letter to lowercase
   - Result: Success, makes the letter uppercase

Test 3: Enter 'A'
   - Verify that nothing is changed
   - Result: Success, value is unchanged

Test 4: Enter 'a'
   - Verify that nothing is changed
   - Result: Success, value is unchanged

Test 5: Enter a digit
   - Verify that 32 is added to the digit
   - Result: Success, 32 is added to the ASCII value of the digit

Test 6: Enter characters that are not between A and Z / 0 and 9
   - Verify that the input value does not change since none of the if blocks are hit
   - Result: Success, value is unchanged

*/