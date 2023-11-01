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
    char userInput[SIZE] = "";
    int matches[MAXMATCHES] = {0};

    while (userInput[0] != '\n')
    {
        printf("Enter a string to search for matches, or enter a blank line to exit the program -> ");
        fgets(userInput, SIZE, stdin);
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

            char targetChar;

            // for char, newline, and '\0'
            char tempBuffer[3];
            printf("Enter character to search for -> ");
            fgets(tempBuffer, 3, stdin);
            targetChar = tempBuffer[0];

            // Clear input buffer again in case the character input also exceeds the buffer
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

                // Print the up arrows under the numbers.
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
