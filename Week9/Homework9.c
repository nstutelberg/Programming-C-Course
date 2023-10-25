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
int *createArray();
void printArray(const int *array, int size);
void printOddValues(const int *array);
void printOddIndexValues(const int *array);
int countEvenValues(const int *array);
int sumValues(const int *array);
int smallestValue(const int *array);
int largestValue(const int *array);
void positiveValsArray(const int *array);
void negativeValsArray(const int *array);

int main()
{
    printf("Homework #9: Nolan Stutelberg\n\n");

    // Seed the random number generator in the main() function so you only do the seeding once
    srand(time(0));

    // Since we are using dynamically created arrays, we can skip the initialization that we had to do in the last homework -> (int myArray[ARY_SIZE], positiveArray[ARY_SIZE], negativeArray[ARY_SIZE];)
    int *myArray = createArray();

    if (myArray)
    {
        printf("The entire array: \n");
        printArray(myArray, ARY_SIZE);

        printf("\nOdd values in the array:\n");
        printOddValues(myArray);

        printf("\n\nNumbers located at odd indexes:\n");
        printOddIndexValues(myArray);

        printf("\nNumber of even numbers in the array: %d\n", countEvenValues(myArray));
        printf("Sum of the array: %d\n", sumValues(myArray));
        printf("Smallest value in array at index %d: %d\n", smallestValue(myArray), myArray[smallestValue(myArray)]);
        printf("Largest value in array at index %d: %d\n", largestValue(myArray), myArray[largestValue(myArray)]);

        printf("\nPositive values in the array are:\n");
        positiveValsArray(myArray);

        printf("\n\nNegative values in the array are:\n");
        negativeValsArray(myArray);

        // After dynamically allocating an array or allocating any memory, it is a good idea to free it so that the memory in use from malloc can be released. If you don't you might take up all the heap space
        // and cause a memory leak
        free(myArray);

        return 0;
    }
    else
    {
        printf("Error in allocating the memory to the array. Exiting the program");
        return -1;
    }
}

int *createArray()
{
    // After this code, array is now pointing to the block of memory where the heap is located. Heaps are for dynamic allocation the size of the array can be resized
    int *array = malloc(ARY_SIZE * sizeof(int));

    // Only execute the code if the array was allocated correctly. Else return NULL
    if (array)
    {
        int *idxP = array;
        const int *endOfArray = array + ARY_SIZE;

        // Nothing needs to be initialized because idxP is already pointing to the start of the array, and you have to do `array + ARY_SIZE` to get the memory location of the last element of the array
        for (; idxP < endOfArray; idxP++)
        {
            *idxP = rand() % (HIGH_LIMIT - LOW_LIMIT + 1) + LOW_LIMIT;
            if (*idxP % NEGMULT1 == 0 || *idxP % NEGMULT2 == 0)
            {
                *idxP = -(*idxP);
            }
        }
        return array;
    }
    // Return NULL instead of -1 because this function is dealing with pointers not values
    return NULL;
}

void printArray(const int *array, int size)
{
    // Same process below as HW8, except that we are accessing the elements of the array using a pointer that points to each subsequent memory address as the loop progresses
    const int *idxP = array;
    int count = 0;
    const int *endOfArray = array + size;

    for (; idxP < endOfArray; idxP++)
    {
        printf("%4d ", *idxP);
        count++;

        if (count == NPERLINE)
        {
            printf("\n");
            count = 0;
        }
    }
}

void printOddValues(const int *array)
{
    // Same process below as HW8, just accessing elements with pointer
    const int *idxP = array;
    int count = 0;
    const int *endOfArray = array + ARY_SIZE;

    for (; idxP < endOfArray; idxP++)
    {
        if (*idxP % 2 != 0)
        {
            printf("%4d ", *idxP);
            count++;
            if (count % NPERLINE == 0)
                printf("\n");
        }
    }
}

void printOddIndexValues(const int *array)
{
    // Same process below as HW8, just accessing elements with pointer
    const int *idxP = array + 1;
    int count = 0;
    const int *endOfArray = array + ARY_SIZE;

    for (; idxP < endOfArray; idxP += 2)
    {
        printf("%4d ", *idxP);
        count++;
        if (count % NPERLINE == 0)
            printf("\n");
    }
}

int countEvenValues(const int *array)
{
    // Same process below as HW8, just accessing elements with pointer
    const int *idxP = array;
    int count = 0;
    const int *endOfArray = array + ARY_SIZE;

    for (; idxP < endOfArray; idxP++)
    {
        if (*idxP % 2 == 0)
            count++;
    }
    return count;
}

int sumValues(const int *array)
{
    // Same process below as HW8, just accessing elements with pointer
    const int *idxP = array;
    int sum = 0;
    const int *endOfArray = array + ARY_SIZE;

    for (; idxP < endOfArray; idxP++)
    {
        sum += *idxP;
    }
    return sum;
}

int smallestValue(const int *array)
{
    // Keeping track of the smallest value in the array with minidxP. We start idxP and minidxP as the first elements in the array, then idxP is incremented each time and compared to minidxP
    // If the value of idxP is smaller, it replaces minidxP.
    const int *idxP = array;
    const int *minidxP = idxP;
    const int *endOfArray = array + ARY_SIZE;

    for (; idxP < endOfArray; idxP++)
    {
        if (*idxP < *minidxP)
            minidxP = idxP;
    }

    // This is set up to subtract the memory locations from where the smallest value is, to where the start of the array is, so you get the actual index of the array. Say the array starts at a memory location
    // of 17436, and the min index is at 17440, then if you subtract those you will know that the min value is at index 4
    return minidxP - array;
}

int largestValue(const int *array)
{
    // Similar process as above
    const int *idxP = array;
    const int *maxidxP = idxP;
    const int *endOfArray = array + ARY_SIZE;

    for (; idxP < endOfArray; idxP++)
    {
        if (*idxP > *maxidxP)
            maxidxP = idxP;
    }
    return maxidxP - array;
}

void positiveValsArray(const int *array)
{

    // Find the amount of positive numbers in the array before creating the new array, so the size is correct
    const int *idxP = array;
    const int *endOfArray = array + ARY_SIZE;
    int posCounter = 0;
    for (; idxP < endOfArray; idxP++)
    {
        if (*idxP > 0)
            posCounter++;
    }

    int *newArray = malloc(posCounter * sizeof(int));
    if (newArray)
    {
        const int *idxP1 = array;
        int *idxP2 = newArray;
        const int *endOfArray = array + ARY_SIZE;

        for (; idxP1 < endOfArray; idxP1++)
        {
            if (*idxP1 > 0)
            {
                *idxP2 = *idxP1;

                // Only move to the next place in newArray if a value is copied
                idxP2++;
            }
        }

        printArray(newArray, posCounter);
        free(newArray);
    }
}

void negativeValsArray(const int *array)
{

    // Find the amount of positive numbers in the array before creating the new array, so the size is correct
    const int *idxP = array;
    const int *endOfArray = array + ARY_SIZE;
    int negCounter = 0;
    for (; idxP < endOfArray; idxP++)
    {
        if (*idxP < 0)
            negCounter++;
    }

    // Same idea as above
    int *newArray = malloc(negCounter * sizeof(int));
    if (newArray)
    {
        const int *idxP1 = array;
        int *idxP2 = newArray;
        const int *endOfArray = array + ARY_SIZE;

        for (; idxP1 < endOfArray; idxP1++)
        {
            if (*idxP1 < 0)
            {
                *idxP2 = *idxP1;
                idxP2++;
            }
        }

        printArray(newArray, negCounter);
        free(newArray);
    }
}

/*
Homework #9: Nolan Stutelberg

The entire array:
 -77  464 -267 -267  527  296  370 -129  349  689
 382 -413 -666  830  479  964  -45  722 -138  323
 341 -765  860  268  580  803  754  758  824  227
 311  715  334 -384  290 -852 -366 -700 -453    5
 311 -147  442  142  916  883  773  139 -306  892
-225 -489  533  236  568    2 -573  953 -369 -915
 505  239  575  236 -786  496 -813  331 -162 -539
-726  -21  911 -117 -686 -156 -791 -414  977 -351
 563  953  607  254   58 -112  253 -615 -882  484
 -70 -957  514  715 -889   76  -90 -231  335 -798

Odd values in the array:
 -77 -267 -267  527 -129  349  689 -413  479  -45
 323  341 -765  803  227  311  715 -453    5  311
-147  883  773  139 -225 -489  533 -573  953 -369
-915  505  239  575 -813  331 -539  -21  911 -117
-791  977 -351  563  953  607  253 -615 -957  715
-889 -231  335

Numbers located at odd indexes:
 464 -267  296 -129  689 -413  830  964  722  323
-765  268  803  758  227  715 -384 -852 -700    5
-147  142  883  139  892 -489  236    2  953 -915
 239  236  496  331 -539  -21 -117 -156 -414 -351
 953  254 -112 -615  484 -957  715   76 -231 -798

Number of even numbers in the array: 47
Sum of the array: 10585
Smallest value in array at index 91: -957
Largest value in array at index 78: 977

Positive values in the array are:
 464  527  296  370  349  689  382  830  479  964
 722  323  341  860  268  580  803  754  758  824
 227  311  715  334  290    5  311  442  142  916
 883  773  139  892  533  236  568    2  953  505
 239  575  236  496  331  911  977  563  953  607
 254   58  253  484  514  715   76  335

Negative values in the array are:
 -77 -267 -267 -129 -413 -666  -45 -138 -765 -384
-852 -366 -700 -453 -147 -306 -225 -489 -573 -369
-915 -786 -813 -162 -539 -726  -21 -117 -686 -156
-791 -414 -351 -112 -615 -882  -70 -957 -889  -90
-231 -798
*/