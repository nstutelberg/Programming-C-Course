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
void printArray(const int *array);
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

    printf("The entire array: \n");
    printArray(myArray);

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

int *createArray()
{
    // After this code, array is now pointing to the block of memory where the heap is located. Heaps are for dynamic allocation the size of the array can be resized
    int *array = malloc(ARY_SIZE * sizeof(int));

    // Only execute the code if the array was allocated correctly. Else return -1
    if (array)
    {
        int *idxP = array;

        // Nothing needs to be initialized because idxP is already pointing to the start of the array, and you have to do `array + ARY_SIZE` to get the memory location of the last element of the array
        for (; idxP < array + ARY_SIZE; idxP++)
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

void printArray(const int *array)
{
    // Same process below as HW8, except that we are accessing the elements of the array using a pointer that points to each subsequent memory address as the loop progresses
    const int *idxP = array;
    int lineCount = 0;

    // The check for *idxP being zero is for the negative and positive value arrays. I didn't want the memory locations to be inserted in the array, so I first initialized all values of the array to 0 first.
    // Then the loop will populate the array with only values, not memory locations. We don't want to print all the trailing zeros, so this condition stops printing when a zero is encountered
    //(since 0s are not in the value range)
    for (; idxP < array + ARY_SIZE && *idxP != 0; idxP++)
    {
        printf("%4d ", *idxP);
        lineCount++;

        if (lineCount == NPERLINE)
        {
            printf("\n");
            lineCount = 0;
        }
    }
}

void printOddValues(const int *array)
{
    // Same process below as HW8, just accessing elements with pointer
    const int *idxP = array;
    int count = 0;

    for (; idxP < array + ARY_SIZE; idxP++)
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
    int numCounter = 0;
    for (; idxP < array + ARY_SIZE; idxP += 2)
    {
        printf("%4d ", *idxP);
        numCounter++;
        if (numCounter % NPERLINE == 0)
            printf("\n");
    }
}

int countEvenValues(const int *array)
{
    // Same process below as HW8, just accessing elements with pointer
    const int *idxP = array;
    int count = 0;
    for (; idxP < array + ARY_SIZE; idxP++)
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
    for (; idxP < array + ARY_SIZE; idxP++)
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
    for (; idxP < array + ARY_SIZE; idxP++)
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
    for (; idxP < array + ARY_SIZE; idxP++)
    {
        if (*idxP > *maxidxP)
            maxidxP = idxP;
    }
    return maxidxP - array;
}

void positiveValsArray(const int *array)
{
    int *newArray = malloc(ARY_SIZE * sizeof(int));
    if (newArray)
    {
        const int *idxP1 = array;
        int *idxP2 = newArray;

        // Fixing an issue from last homework where memory addresses would populate the array. We want to initialize all elements of the array to 0 first so memory locations are not included in the array
        for (; idxP2 < newArray + ARY_SIZE; idxP2++)
        {
            *idxP2 = 0;
        }

        // Reset idxP2 to the start of the memory block of the array so values can be inserted starting from the first slot
        idxP2 = newArray;

        for (; idxP1 < array + ARY_SIZE; idxP1++)
        {
            if (*idxP1 > 0)
            {
                *idxP2 = *idxP1;

                // Only move to the next place in newArray if a value is copied
                idxP2++;
            }
        }

        printArray(newArray);
        free(newArray);
    }
}

void negativeValsArray(const int *array)
{

    // Same idea as above
    int *newArray = malloc(ARY_SIZE * sizeof(int));
    if (newArray)
    {
        const int *idxP1 = array;
        int *idxP2 = newArray;

        // Fixing the same issue as with positiveValsArray
        for (; idxP2 < newArray + ARY_SIZE; idxP2++)
        {
            *idxP2 = 0;
        }

        // Reset idxP2 to the start of the memory block
        idxP2 = newArray;

        for (; idxP1 < array + ARY_SIZE; idxP1++)
        {
            if (*idxP1 < 0)
            {
                *idxP2 = *idxP1;
                idxP2++;
            }
        }

        printArray(newArray);
        free(newArray);
    }
}

/*
Homework #9: Nolan Stutelberg

The entire array:
-732 -329  -24  209  -72 -552  542  967 -423  502
-207  829  464 -518  697  -66 -651  206 -279  -45
 191  419 -942  713 -279 -864  118 -561  118  520
-687  268  262 -327  232 -288  787  758 -819  958
 640 -492   79 -600 -858  625  268 -792  625 -438
-875   85 -245  944   68 -750  194 -252  916  799
 358  148  127 -300  379 -952  790 -417  646  253
 692 -791  254  130  494  292  638  143  116  163
  34  -57 -648 -597 -477  548  316  344 -858 -333
 613  794  172  716 -749  359  683 -204  907 -771

Odd values in the array:
-329  209  967 -423 -207  829  697 -651 -279  -45
 191  419  713 -279 -561 -687 -327  787 -819   79
 625  625 -875   85 -245  799  127  379 -417  253
-791  143  163  -57 -597 -477 -333  613 -749  359
 683  907 -771

Numbers located at odd indexes:
-329  209 -552  967  502  829 -518  -66  206  -45
 419  713 -864 -561  520  268 -327 -288  758  958
-492 -600  625 -792 -438   85  944 -750 -252  799
 148 -300 -952 -417  253 -791  130  292  143  163
 -57 -597  548  344 -333  794  716  359 -204 -771

Number of even numbers in the array: 57
Sum of the array: 4991
Smallest value in array at index 65: -952
Largest value in array at index 7: 967

Positive values in the array are:
 209  542  967  502  829  464  697  206  191  419
 713  118  118  520  268  262  232  787  758  958
 640   79  625  268  625   85  944   68  194  916
 799  358  148  127  379  790  646  253  692  254
 130  494  292  638  143  116  163   34  548  316
 344  613  794  172  716  359  683  907

Negative values in the array are:
-732 -329  -24  -72 -552 -423 -207 -518  -66 -651
-279  -45 -942 -279 -864 -561 -687 -327 -288 -819
-492 -600 -858 -792 -438 -875 -245 -750 -252 -300
-952 -417 -791  -57 -648 -597 -477 -858 -333 -749
-204 -771
*/