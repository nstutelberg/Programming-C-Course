// HW #11, Nolan Stutelberg
#include <stdio.h>
#include <string.h>
#define SIZE 41
#define MAXMATCHES 10

int charIsAt(char *pStr, char ch, int loc[], int mLoc);
void clearInputBuffer();

int main()
{
    printf("HW #11, Nolan Stutelberg\n\n");
    char userInput[SIZE];
    int matches[MAXMATCHES];

    while (userInput[0] != '\n')
    {
        printf("Enter a string to search for matches, or enter a blank line to exit the program -> ");
        fgets(userInput, SIZE, stdin);

        // Getting the input length to reuse in various calculations, as to not get outOfBounds errors and clear input buffers
        int inputLength = strlen(userInput);

        if (userInput[inputLength - 1] != '\n')
        {
            clearInputBuffer();
        }

        if (userInput[0] != '\n')
        {

            // Notify the user that their input was truncated if they enter a string longer than SIZE
            if (inputLength == SIZE - 1)
            {
                printf("Input truncated to %d characters -> %s\n\n", SIZE - 1, userInput);
            }

            // Below is setting a temporary buffer for teh user input and setting it to 3, because 1 is for a character the user enters, one is for the end of the string (null terminator), and one is for the end of the string
            // This section of the code makes sure that the first character the user enters is used.. So you can enter `aousdhfiauoshf` as the targetChar, and only `a` will actually be used
            char targetChar;
            char tempBuffer[3];
            printf("Enter character to search for -> ");
            fgets(tempBuffer, 3, stdin);
            targetChar = tempBuffer[0];

            // Clear input buffer again in case the character input exceeds 1 character. This is so the next steps won't use leftover characters that are being stored in the buffer
            if (tempBuffer[strlen(tempBuffer) - 1] != '\n')
            {
                clearInputBuffer();
            }

            int count = charIsAt(userInput, targetChar, matches, MAXMATCHES);
            printf("\nThe character '%c' was found %d time(s) in the word you inputted.", targetChar, count);

            // Only execute the rest of the code if there were any matches at all. Or else just return 0 and exit the program
            if (count > 0)
            {
                printf("\nThe %d matches are at the following index/indices-> ", count);
                for (int i = 0; i < count && i < MAXMATCHES; i++)
                {
                    printf("%d ", matches[i]);
                }

                printf("and the positions in the string where matches were found are shown below \n%s", userInput);

                if (inputLength == SIZE - 1)
                {
                    printf("\n");
                }

                // Print the up arrows only at the positions where there were matches. the charIsAt function populates the matches array with indices for all the matched characters, so that array is used to tell
                // the program when to print out the '^' and when to print a ' '
                for (int i = 0, j = 0; userInput[i] != '\0'; i++)
                {
                    if (j < count && i == matches[j])
                    {
                        printf("^");
                        j++;
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n\n");
            }
        }
    }

    return 0;
}

int charIsAt(char *pStr, char ch, int loc[], int mLoc)
{
    int count = 0;

    // Using `\0` as a way to determine where the end of the string is. Since the size of the string can vary, we need to check for this null terminator character to see when a blank line is encountered
    // Also checking for a new line character, so if the user hits Enter, then the loop will break as well
    for (int i = 0; *(pStr + i) != '\0' && *(pStr + i) != '\n'; i++)
    {
        // Starting at the beginning of the array and moving the pointer i positions forward each time, check if the current character matches the target character
        // Also the second condition is there to make sure that the program doesn't go out of bounds. This is making sure the max amount of matches you can have is the length of the array
        if (*(pStr + i) == ch && count < mLoc)
        {
            loc[count] = i;
            count++;
        }
    }
    return count;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/*
Sample output:

HW #11, Nolan Stutelberg

Enter a string to search for matches, or enter a blank line to exit the program -> hello prof pottebaum whats good
Enter character to search for -> p

The character 'p' was found 2 time(s) in the word you inputted.
The 2 matches are at the following index/indices-> 6 11 and the positions in the string where matches were found are shown below
hello prof pottebaum whats good
      ^    ^

Enter a string to search for matches, or enter a blank line to exit the program -> thisisareallylongstringthatwillbetruncatedweeeeeeeeeeeeeeeeeeeeeeeeeee
Input truncated to 40 characters -> thisisareallylongstringthatwillbetruncat

Enter character to search for -> l

The character 'l' was found 5 time(s) in the word you inputted.
The 5 matches are at the following index/indices-> 10 11 13 29 30 and the positions in the string where matches were found are shown below
thisisareallylongstringthatwillbetruncat
          ^^ ^               ^^

Enter a string to search for matches, or enter a blank line to exit the program ->
PS C:\Users\nstut\git\Programming-C-Course\Week11>
*/