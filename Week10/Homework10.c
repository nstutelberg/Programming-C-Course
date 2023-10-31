// HW #10, Nolan Stutelberg
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SETS 10

void underscorePrinter(int numColumns);
int getNumSets();
int getNumPts();
int getNumStartEndPts();
double *createDataset(int n);
void sortArray(double *PArray, int n);
double average(double *PArray, int n);

int main()
{
    printf("HW #10: Nolan Stutelberg\n");
    srand(time(0));
    int nSets = getNumSets();
    int nPtsToPrint = getNumStartEndPts();

    // Dynamically printing the heading with the new requirements, such that the header will always be formatted depending on the number of columns
    // The below calculation is using the fact that we have width specifiers for all the random generated values, so we know the width of the data depending on the number of columns
    // Including blank spaces, 8 is the amount of spaces that one data point takes up ` 0.0095 `, 14 is the length of ` FirstDataPts `, and dividing by two evenly distributes the underscores
    int underscoresToPrint = ((nPtsToPrint * 8) - 14) / 2;
    printf("Set #   Npts   Average   ");
    underscorePrinter(underscoresToPrint);
    printf("FirstDataPts");
    underscorePrinter(underscoresToPrint);
    printf("       ");
    underscorePrinter(underscoresToPrint);
    printf("LastDataPts");
    underscorePrinter(underscoresToPrint);
    printf("\n");

    // Putting dblArray on the stack and the individual datasets on the heap
    // Specifying the size of the array as 10 to account for the NULL POINTER that will always be at set #10. Used a #define statement to always create 10 arrays,
    // since using nSets to create the array would need dynamic memory allocation, which was more complicated when I tried it
    double *dblArray[MAX_SETS];

    // Populating the array with pointers to arrays of the random data that we generated
    for (int i = 0; i < nSets; i++)
    {
        int nPts = getNumPts();
        dblArray[i] = createDataset(nPts);
    }

    // Setting the final value of the dataset to a NULL pointer so we can know where the end of the array is.
    // There is at maximum 10 sets printed (0-9). Previously I didn't have the if statement, so I was getting out of bounds behavior when there were 10 sets
    if (nSets < MAX_SETS)
    {
        dblArray[nSets] = NULL;
    }

    // Fix the segmentation fault by avoiding accessing memory that has not been initialized yet
    // These loop conditions make sure that the loop is bound to the number of datasets that should be printed
    for (int i = 0; i < nSets && dblArray[i] != NULL; i++)
    {
        int nPts = getNumPts();
        double avg = average(dblArray[i], nPts);
        sortArray(dblArray[i], nPts);

        printf(" %3d   %5d   %7.4f ", i, nPts, avg);
        for (int j = 0; j < nPtsToPrint; j++)
            printf(" %7.4f", dblArray[i][j]);

        printf(" ... ");

        for (int j = nPts - nPtsToPrint; j < nPts; j++)
            printf(" %7.4f", dblArray[i][j]);

        printf("\n");
    }

    // After printing the data, making sure to free the memory of each array that was generated through the createDataset function
    for (int i = 0; i < nSets && dblArray[i] != NULL; i++)
    {
        free(dblArray[i]);
    }

    return 0;
}

void underscorePrinter(int numUnderscores)
{
    // Instead of looping for how many underscores to print, I set a max of 9 underscores to print at each call of the function. With 4 columns, 9 underscores is the perfect width
    // There needs to be sufficient underscores to populate the print statement in the case of getNumStartEndPts returning 4, so with this logic, there will always be enough underscores
    // Need the `.` in order to give the precision as an argument to the printf function. If you take out the ., the spacing will be broken if you try it out
    printf("%.*s", numUnderscores, "_________");
}

int getNumSets()
{
    return rand() % 6 + 5;
}

int getNumStartEndPts()
{
    return rand() % 3 + 2;
}

int getNumPts()
{
    return 1000 * (rand() % 8 + 4);
}

double *createDataset(int n)
{
    double *dblArray = (double *)malloc(n * sizeof(double));

    if (dblArray)
    {
        double *end = dblArray + n;
        double *current = dblArray;

        for (; current < end; current++)
        {
            // Populate the array with values ranging from 0 to 10 inclusive
            *current = rand() * 10.0 / RAND_MAX;
        }
    }
    return dblArray;
}

void sortArray(double *pArray, int n)
{
    double *end = pArray + n;
    // Perform the selcetion sort algorithm to sort in asc order. This algorithm has O(n^2) time complexity and I believe the only way to improve the run time further would be to use a different sorting method
    for (double *i = pArray; i < end - 1; i++)
    {
        double *pMinIdx = i;
        for (double *j = i + 1; j < end; j++)
            if (*j < *pMinIdx)
                pMinIdx = j;

        // Use the temp variable so you can swap min index and current element and place the next smallest value just to the right of the current smallest value in the array
        double temp = *pMinIdx;
        *pMinIdx = *i;
        *i = temp;
    }
}

double average(double *pArray, int n)
{
    double sum = 0;
    // Pointer to one past the end of the array
    double *pEnd = pArray + n;

    for (double *p = pArray; p < pEnd; p++)
    {
        sum += *p;
    }

    return (sum / n);
}

/*
Sample Output

HW #10: Nolan Stutelberg
Set #   Npts   Average   _________FirstDataPts_________       _________LastDataPts_________
   0    6000    5.0171   0.0015  0.0018  0.0034  0.0040 ...   9.9896  9.9976  9.9991  9.9994
   1   11000    5.0551   0.0000  0.0000  0.0003  0.0006 ...   9.9963  9.9966  9.9985  9.9985
   2    4000    7.7299   0.0049  0.0052  0.0162  0.0177 ...   9.9966  9.9979  9.9985  9.9985
   3    8000    5.0374   0.0000  0.0000  0.0006  0.0009 ...   9.9979  9.9982  9.9985 10.0000
   4    9000    5.5214   0.0012  0.0049  0.0052  0.0061 ...   9.9979  9.9982  9.9985 10.0000
   5    4000    4.9836   0.0046  0.0061  0.0140  0.0143 ...   9.9930  9.9936  9.9939  9.9979

HW #10: Nolan Stutelberg
Set #   Npts   Average   _____FirstDataPts_____       _____LastDataPts_____
   0    6000    5.0263   0.0000  0.0000  0.0006 ...   9.9991  9.9991  9.9994
   1   10000    5.3921   0.0000  0.0000  0.0015 ...   9.9994  9.9994  9.9997
   2   10000    6.1860   0.0000  0.0000  0.0009 ...   9.9994  9.9994  9.9997
   3   11000    5.4174   0.0000  0.0000  0.0009 ...   9.9994  9.9994  9.9997
   4   10000    6.6502   0.0000  0.0000  0.0027 ...   9.9994  9.9994  9.9997
   5    4000    7.3430   0.0003  0.0006  0.0037 ...   9.9994  9.9994  9.9997
   6    7000    4.9382   0.0003  0.0003  0.0015 ...   9.9908  9.9997 10.0000
   7    7000    4.9885   0.0000  0.0000  0.0009 ...   9.9973  9.9976  9.9982
   8    4000    6.8091   0.0015  0.0040  0.0079 ...   9.9973  9.9976  9.9982

HW #10: Nolan Stutelberg
Set #   Npts   Average   _FirstDataPts_       _LastDataPts_
   0   10000    4.9598   0.0000  0.0000 ...   9.9994  9.9997
   1    7000    6.7081   0.0058  0.0085 ...   9.9994  9.9997
   2    7000    5.0113   0.0015  0.0027 ...   9.9969  9.9994
   3    5000    5.0314   0.0000  0.0006 ...   9.9985  9.9991
   4    9000    5.0129   0.0000  0.0000 ...   9.9994  9.9997
   5   11000    6.0140   0.0000  0.0000 ...   9.9994  9.9997
   6    5000    5.9394   0.0000  0.0058 ...   9.9994  9.9997


*/