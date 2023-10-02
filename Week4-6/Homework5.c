// HW #05, Nolan Stutelberg
#include <stdio.h>
#include <ctype.h>

// Declaring function prototype
void ifElseFunction(char charVal);

int main(void)
{
    printf("HW #05, Nolan Stutelberg\n\n");
    int userInputInt;
    int validValue = 0;

    // While loop here to keep looping until the user enters a valid value. If the value is invalid, the program will request the input again
    while (validValue == 0) {

        printf("Enter a positive integer value that is less than 20 -> ");
        scanf("%d", &userInputInt);
    
        if (userInputInt < 20 && userInputInt >= 0) {
            validValue = 1;
        } else {
            printf("Enter a valid value pal\n");
        }    
    }

    // Getting the sum of all the numbers from 0 up to (and including) the user input value
    int runningSum = 0;
    for (int i = 0; i <= userInputInt; i++) {
        runningSum += i;
    }

    printf("The user entered the value -> %d\n", userInputInt);
    printf("The sum of all the numbers up to the user input value is -> %d\n", runningSum);

    // Prompt user to enter the char now. The user can enter multiple chars at once and the code will work fine, but the output is formatted best when the user enters just one char
    printf("\nNow enter in a character here ->");
    char userInputChar;
    scanf(" %c", &userInputChar);

    while (userInputChar != '#') {

        ifElseFunction(userInputChar);

        // Enter another character to keep the loop going.
        printf("\nEnter another character or use # to exit ->");
        scanf(" %c", &userInputChar);

    }

    return 0;

}

// Function below is directly copied from homework 4

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

  

/*

HW #05, Nolan Stutelberg

Enter a positive integer value that is less than 20 -> -1
Enter a valid value pal
Enter a positive integer value that is less than 20 -> 21
Enter a valid value pal
Enter a positive integer value that is less than 20 -> 20
Enter a valid value pal
Enter a positive integer value that is less than 20 -> 19
The user entered the value -> 19
The sum of all the numbers up to the user input value is -> 190

Now enter in a character here ->Aj*

Executing the If/Else function...
Using the user char input of: A
The resulting value is: A

Enter another character or use # to exit ->
Executing the If/Else function...
Using the user char input of: j
The resulting value is: J

Enter another character or use # to exit ->
Executing the If/Else function...
Using the user char input of: *
The resulting value is: *

Enter another character or use # to exit ->U

Executing the If/Else function...
Using the user char input of: U
The resulting value is: u

Enter another character or use # to exit ->#

*/

/*

Test Plan (excluding tests from previous homework):

    1. Make sure that only the values 0 to 19 work for user input for the summation portion
        - See the example output. Works correctly

    2. Confirm that the sum is being calculated correctly
        - Took 19 as an example, and adding numbers 1 all the way through 19 does in fact give 190
    
    3. Confirm that the for loop will exit
        - For loop exits right aftr the calculations are done
    
    3. Confirm that as long as the user enters a character that isn't the `#` symbol, the loop will continue
        - Shown in example output. User can input whatever character they want and program will never end, until the `#` is encountered

*/