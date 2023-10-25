#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getNumSets();
int getNumPts();
double *createDataset(int n);
void sortArray(double *PArray, int n);
double average(double *PArray, int n);

int main()
{
    printf("HW #10: Nolan Stutelberg\n");
    printf("Set #   Npts   Average  ________First_Data_Pts________      ______Last_Data_Pts___________\n");

    // Seed the random number generator in the main() function so you only do the seeding once
    srand(time(0));

    int nSets = getNumSets();

    // Creating the dataset, and setting the final value of the dataset to a NULL pointer so we can know where the end of the array is. The ** is used here because we are using 2D arrays (arrays of arrays)
    double **dblArray = malloc((nSets + 1) * sizeof(double *));
    dblArray[nSets] = NULL;

    // Populating the array with pointers to arrays of the random data that we generated
    for (int i = 0; i < nSets; i++)
    {
        int nPts = getNumPts();
        dblArray[i] = createDataset(nPts);
    }

    // Loop through each dataset and calculate the metrics for each one, except for the null pointer at the end of the array
    for (int i = 0; dblArray[i] != NULL; i++)
    {
        int nPts = getNumPts();
        double avg = average(dblArray[i], nPts);
        sortArray(dblArray[i], nPts);

        printf(" %3d   %5d   %7.4f %7.4f %7.4f %7.4f %7.4f ... %7.4f %7.4f %7.4f %7.4f\n", i, nPts, avg, dblArray[i][0], dblArray[i][1], dblArray[i][2], dblArray[i][3], dblArray[i][nPts - 4], dblArray[i][nPts - 3], dblArray[i][nPts - 2], dblArray[i][nPts - 1]);
    }

    // After printing the data, making sure to free the memory of each pointer, and lastly, free the memory of the general dblArray
    for (int i = 0; dblArray[i] != NULL; i++)
    {
        free(dblArray[i]);
    }
    free(dblArray);

    return 0;
}

int getNumSets()
{
    return rand() % 6 + 5;
}

int getNumPts()
{
    return 1000 * (rand() % 8 + 4);
}

double *createDataset(int n)
{
    double *dblArray = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
    {
        // Populate the array with values ranging from 0 to 10 inclusive
        dblArray[i] = rand() * 10.0 / RAND_MAX;
    }

    return dblArray;
}

void sortArray(double *pArray, int n)
{
    // Perform the selcetion sort algorithm to sort in asc order. This algorithm has O(n^2) time complexity and I believe the only way to improve the run time further would be to use a different sorting method
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (pArray[j] < pArray[minIdx])
                minIdx = j;

        // Use the temp variable so you can swap pArray[minIdx] and pArray[i] and place the next smallest value just to the right of the current smallest value in the array
        double temp = pArray[minIdx];
        pArray[minIdx] = pArray[i];
        pArray[i] = temp;
    }
}

double average(double *pArray, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += pArray[i];
    }

    return (sum / n);
}

/*
Sample Output

HW #10: Nolan Stutelberg
Set #   Npts   Average  ________First_Data_Pts________      ______Last_Data_Pts___________
   0   10000    4.9803  0.0000  0.0000  0.0000  0.0015 ...  9.9936  9.9951  9.9963  9.9988
   1    4000    5.9870  3.9567  3.9586  3.9604  3.9607 ...  8.0313  8.0328  8.0331  8.0334
   2    9000    5.0261  0.0000  0.0000  0.0009  0.0015 ...  9.9982  9.9982  9.9985  9.9997
   3    7000    6.6245  0.0012  0.0015  0.0067  0.0101 ...  9.9982  9.9982  9.9985  9.9997
   4    5000    5.0620  0.0015  0.0027  0.0043  0.0052 ...  9.9985  9.9988  9.9988  9.9991
   5    6000    5.0946  0.0009  0.0018  0.0024  0.0037 ...  9.9918  9.9927  9.9951  9.9966
   6   11000    4.9857  0.0000  0.0000  0.0015  0.0018 ...  9.9966  9.9973  9.9991  9.9997

*/