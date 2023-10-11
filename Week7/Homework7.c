// HW #07, Nolan Stutelberg
#include <stdio.h>

// Prototype
float readInFloat();

int main()
{

    printf("HW #07, Nolan Stutelberg\n\n");
    char inputCharacter;
    float num1, num2, result;

    while (inputCharacter != 'q')
    {
        printf("What operation would you like to use?\na. Addition\ns. Subtraction\nm. Multiplication\nd. Division\nq. Quit\n");
        printf("Choose an operation: ");
        scanf("%c", &inputCharacter);

        // Clear input buffer so the user can enter fresh user input
        while (getchar() != '\n')
            ;

        // Check for q right after the scanning so the code does not execute anything else if q is encountered
        if (inputCharacter != 'q')
        {

            if (inputCharacter != 'a' && inputCharacter != 's' && inputCharacter != 'm' && inputCharacter != 'd')
            {
                printf("Invalid option. Try again.\n");
            }
            else
            {

                printf("Enter the first number: ");
                num1 = readInFloat("Enter the first number: ");
                printf("Enter the second number: ");
                num2 = readInFloat("Enter the second number: ");

                switch (inputCharacter)
                {
                case 'a':
                    result = num1 + num2;
                    printf("%g + %g = %g\n", num1, num2, result);
                    break;
                case 's':
                    result = num1 - num2;
                    printf("%g - %g = %g\n", num1, num2, result);
                    break;
                case 'm':
                    result = num1 * num2;
                    printf("%g * %g = %g\n", num1, num2, result);
                    break;
                case 'd':
                    while (num2 == 0)
                    {
                        printf("Cannot divide by zero. Enter another number: ");
                        num2 = readInFloat();
                    }
                    result = num1 / num2;
                    printf("%g / %g = %g\n", num1, num2, result);
                    break;
                }
            }
        }
    }
    printf("Calculator exited.\n");
    return 0;
}

// Function to get float input
float readInFloat()
{
    float inputNumber;
    int status = 0;

    // Loop until a correct character is entered and a success status is returned. When a valid number is entered, status is assigned the value of 1, and the while loop exits
    while (status == 0)
    {
        status = scanf("%f", &inputNumber);
        while (getchar() != '\n')
            ;
        if (status == 0)
            printf("Invalid input. Please enter a number: ");
    }

    return inputNumber;
}

/*
Example Output:

HW #07, Nolan Stutelberg

What operation would you like to use?
a. Addition
s. Subtraction
m. Multiplication
d. Division
q. Quit
Choose an operation: d
Enter the first number: k
Invalid input. Please enter a number: k
Invalid input. Please enter a number: 9
Enter the second number: a
Invalid input. Please enter a number: 3
9 / 3 = 3
What operation would you like to use?
a. Addition
s. Subtraction
m. Multiplication
d. Division
q. Quit
Choose an operation: a
Enter the first number: u
Invalid input. Please enter a number: 8
Enter the second number: 3
8 + 3 = 11
What operation would you like to use?
a. Addition
s. Subtraction
m. Multiplication
d. Division
q. Quit
Choose an operation: ak
Enter the first number: 2
Enter the second number: 9
2 + 9 = 11
What operation would you like to use?
a. Addition
s. Subtraction
m. Multiplication
d. Division
q. Quit
Choose an operation: q
Calculator exited.

*/
/*
    Test Plan:

    1. Verify addition works with single characters
       Input: a, num1 = 5, num2 = 3
       Expected Output: "5 + 3 = 8"

    2. Verify subtraction works with decimals and for giving a negative number
       Input: s, num1 = 2.5, num2 = 10.0
       Expected Output: "2.5 - 10.0 = -7.5"

    3. Verify multiplication works
       Input: m, num1 = 2.501, num2 = 3.539
       Expected Output: "8.182 * 0.3814 = 3.12061"

    4. verify if you try to divide by zero, program won't let you and will make you enter a new value
       Input: d, num1 = 1, num2 = 0,
       Expected Output: "Cannot divide by zero. Enter another number: "

    5. Verify that if you enter a character into the number field, it will prompt for new number
       Input: a, num1 = u, num1 = 8, num2 = 3
       Expected Output: "Enter the first number: u" "Invalid input. Please enter a number: "

    6. Verify the calculator quits when you enter 'q'
       Input: q
       Expected Output: "Calculator exited."

    7. Verify that entering an invalid character makes you re-enter a character
       Input: l
       Expected Output: "Invalid option. Try again."

    8. Validating that additional characters are ignored for operation selection
        Input: mk, 8 4
        Expected Output: "8 * 4 = 32"
*/
