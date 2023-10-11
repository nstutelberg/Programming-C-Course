#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Setting all the constants
#define ARY_SIZE 100
#define LOW_LIMIT 1
#define HIGH_LIMIT 999
#define NPERLINE 10
#define NEGMULT1 3
#define NEGMULT2 7

// Function prototypes
void createArray(int array[]);
void printArray(const int array[]);
void printOddValues(const int array[]);
void printOddIndexValues(const int array[]);
int countEvenValues(const int array[]);
int sumValues(const int array[]);
int smallestValue(const int array[]);
int largestValue(const int array[]);
void positiveValsArray(const int array[], int newArray[]);
void negativeValsArray(const int array[], int newArray[]);

int main()
{
    printf("Homework #8: Nolan Stutelberg\n\n");

    int myArray[ARY_SIZE], positiveArray[ARY_SIZE], negativeArray[ARY_SIZE];

    // Below code is needed in order to get different array numbers each time. Uses the current time to set a different starting point for the random number generator,
    // leading to different numbers being printed in the arrays for each run
    srand(time(0));

    createArray(myArray);

    // Final printed outputs
    printf("The entire array: \n");
    printArray(myArray);

    printf("\nOdd values in the array:\n");
    printOddValues(myArray);

    printf("\n\nNumbers located at odd indexes:\n");
    printOddIndexValues(myArray);

    printf("\nNumber of even numbers in the array: %d\n", countEvenValues(myArray));
    printf("Sum of the array: %d\n", sumValues(myArray));
    printf("Smallest value in array: %d\n", myArray[smallestValue(myArray)]);
    printf("Largest value in array: %d\n", myArray[largestValue(myArray)]);

    positiveValsArray(myArray, positiveArray);
    negativeValsArray(myArray, negativeArray);

    printf("\nPositive values in the array are:\n");
    printArray(positiveArray);

    printf("\n\nNegative values in the array are:\n");
    printArray(negativeArray);

    return 0;
}

// In the functions below, const will be used in the functions where the array should not be modified. Otherwise, the array will have a modification applied to it
void createArray(int array[])
{
    for (int i = 0; i < ARY_SIZE; i++)
    {
        // Want all myArray inclusive from 1 to 999. not including 0 or 1000
        array[i] = rand() % (HIGH_LIMIT - LOW_LIMIT + 1) + LOW_LIMIT;
        if (array[i] % NEGMULT1 == 0 || array[i] % NEGMULT2 == 0)
        {
            array[i] = -array[i];
        }
    }
}

void printArray(const int array[])
{
    for (int i = 0; i < ARY_SIZE && array[i] != 0; i++)
    {
        // Ensure alignment is correct since we know each value will be at max 4 characters. And add a space between each number so they don't merge together
        printf("%4d ", array[i]);

        // C indexes at 0, so once the loop executes enough times to be equal to the defined constant for how many numbers on a line, print a new line
        if ((i + 1) % NPERLINE == 0)
        {
            printf("\n");
        }
    }
}

void printOddValues(const int array[])
{
    // Need the count variable to track how many odd numbers are printed, since not every index will contain an odd number
    int count = 0;
    for (int i = 0; i < ARY_SIZE; i++)
    {
        // Condition that checks if the number is even or not
        if (array[i] % 2 != 0)
        {
            printf("%4d ", array[i]);
            count++;
            if (count % NPERLINE == 0)
                printf("\n");
        }
    }
}

void printOddIndexValues(const int array[])
{
    // Start at index 1, and add 2 each time so only the odd indices are printed (1,3,5,7 etc)
    for (int i = 1; i < ARY_SIZE; i += 2)
    {
        printf("%4d ", array[i]);
        if ((i + 1) / 2 % NPERLINE == 0)
            printf("\n");
    }
}

int countEvenValues(const int array[])
{
    int count = 0;
    for (int i = 0; i < ARY_SIZE; i++)
    {
        if (array[i] % 2 == 0)
            count++;
    }
    return count;
}

int sumValues(const int array[])
{
    int sum = 0;
    for (int i = 0; i < ARY_SIZE; i++)
    {
        sum += array[i];
    }
    return sum;
}

int smallestValue(const int array[])
{
    // Compare current value to previous value and store the smaller value. Need to start at index of 1 in order to compare index 1 vs index 0
    int startingIndex = 0;
    for (int i = 1; i < ARY_SIZE; i++)
    {
        if (array[i] < array[startingIndex])
            startingIndex = i;
    }
    return startingIndex;
}

int largestValue(const int array[])
{
    int startingIndex = 0;
    for (int i = 1; i < ARY_SIZE; i++)
    {
        if (array[i] > array[startingIndex])
            startingIndex = i;
    }
    return startingIndex;
}

void positiveValsArray(const int array[], int newArray[])
{
    // Below loop is solving an issue where I had garbage memory data in my final arrays because the new arrays that were created didn't have all their values initialized at 0.
    // The below loop goes through every index of the new array and initializes the values, so that printArray will stop printing values when it reaches a 0, and garbage data won't be printed
    for (int i = 0; i < ARY_SIZE; i++)
    {
        newArray[i] = 0;
    }

    int insertIndex = 0;
    for (int i = 0; i < ARY_SIZE; i++)
    {
        if (array[i] > 0)
        {
            newArray[insertIndex] = array[i];
            insertIndex++;
        }
    }
}

void negativeValsArray(const int array[], int newArray[])
{
    for (int i = 0; i < ARY_SIZE; i++)
    {
        newArray[i] = 0;
    }

    int insertIndex = 0;
    for (int i = 0; i < ARY_SIZE; i++)
    {
        if (array[i] < 0)
        {
            newArray[insertIndex] = array[i];
            insertIndex++;
        }
    }
}

/**
Homework #8: Nolan Stutelberg

The entire array:
 -72  598  146  499  695  811 -534 -777  130 -896
-135 -174  475  271  713 -918 -261  110  676  598
-489  -90  929 -889 -162 -528  767 -582 -693   29
-621 -234  248  776 -492  976  -27 -791 -889  599
 712  263  302  634  521  319 -228  562 -672 -910
-789  479  895  379 -549  136   25    2 -168 -870
 664  257  713  988  601 -322  653  268 -140 -744
-159 -763 -222 -195 -138 -996  734  -35  -28  886
  43  626  170  116  563  506 -792   89  613 -343
  31  382 -549   20  391 -819  230  338  716 -912

Odd values in the array:
 499  695  811 -777 -135  475  271  713 -261 -489
 929 -889  767 -693   29 -621  -27 -791 -889  599
 263  521  319 -789  479  895  379 -549   25  257
 713  601  653 -159 -763 -195  -35   43  563   89
 613 -343   31 -549  391 -819

Numbers located at odd indexes:
 598  499  811 -777 -896 -174  271 -918  110  598
 -90 -889 -528 -582   29 -234  776  976 -791  599
 263  634  319  562 -910  479  379  136    2 -870
 257  988 -322  268 -744 -763 -195 -996  -35  886
 626  116  506   89 -343  382   20 -819  338 -912

Number of even numbers in the array: 54
Sum of the array: 4276
Smallest value in array: -996
Largest value in array: 988

Positive values in the array are:
 598  146  499  695  811  130  475  271  713  110
 676  598  929  767   29  248  776  976  599  712
 263  302  634  521  319  562  479  895  379  136
  25    2  664  257  713  988  601  653  268  734
 886   43  626  170  116  563  506   89  613   31
 382   20  391  230  338  716

Negative values in the array are:
 -72 -534 -777 -896 -135 -174 -918 -261 -489  -90
-889 -162 -528 -582 -693 -621 -234 -492  -27 -791
-889 -228 -672 -910 -789 -549 -168 -870 -322 -140
-744 -159 -763 -222 -195 -138 -996  -35  -28 -792
-343 -549 -819 -912
*/