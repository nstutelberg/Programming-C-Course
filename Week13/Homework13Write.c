// HW #13, Nolan Stutelberg
// Note - more comments will be in this file since some things are repeated in the read portion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// My system allows empty file names, so FILE_PATH will remain an empty string
#define FILE_PATH ""
#define MAX_FILENAME 25
#define EXTENSION ".xxx"

typedef struct
{
    int dataSetNum;
    int numOfDoubles;
    double avgAllVals;
    double *dataArr;
} DataSet;

int getNumPoints();
double getRandDouble();
FILE *openWrBinaryFile(char *filename);
void calculateAvgAllVals(DataSet *myVLA);

int main()
{
    printf("HW #13, Nolan Stutelberg \n");
    srand(time(0));

    char filename[MAX_FILENAME] = {0};
    FILE *file = openWrBinaryFile(filename);

    if (file)
    {
        // Creating the array containing the pointers to 2 VLA structs
        DataSet *myVLA[2];
        for (int i = 0; i < 2; ++i)
        {
            // First allocate struct on the heap then allocating the arrays according to the double value generated from getNumPoints()
            myVLA[i] = (DataSet *)malloc(sizeof(DataSet));
            myVLA[i]->dataSetNum = i + 1;
            myVLA[i]->numOfDoubles = getNumPoints();
            myVLA[i]->dataArr = (double *)malloc(myVLA[i]->numOfDoubles * sizeof(double));

            // Populating the VLAs
            for (int j = 0; j < myVLA[i]->numOfDoubles; ++j)
            {
                myVLA[i]->dataArr[j] = getRandDouble();
            }

            // Doing the calculatiosn
            calculateAvgAllVals(myVLA[i]);

            // Write to the .xxx file once metrics are calculated
            fwrite(myVLA[i], sizeof(DataSet), 1, file);
            fwrite(myVLA[i]->dataArr, sizeof(double), myVLA[i]->numOfDoubles, file);

            printf("\nWrote Dataset #%d to %s: %lu bytes", myVLA[i]->dataSetNum, filename, sizeof(DataSet) + sizeof(double) * myVLA[i]->numOfDoubles);
            printf("\nThe set contains %d points, the avgAllVals is %.4f\n", myVLA[i]->numOfDoubles, myVLA[i]->avgAllVals);
        }

        // Doing memory management by freeing the memory that was allocated
        fclose(file);
        for (int i = 0; i < 2; ++i)
        {
            free(myVLA[i]->dataArr);
            free(myVLA[i]);
        }
    }

    return 0;
}

int getNumPoints()
{
    int N = 200 * (rand() % 5 + 1);
    return N;
}

double getRandDouble()
{
    double D = 20.0 * rand() / RAND_MAX;
    return D;
}

FILE *openWrBinaryFile(char *filename)
{
    printf("Enter a new filename without an extension (<%d characters)\nor press [Enter] to use the default name:\n", MAX_FILENAME - strlen(EXTENSION) - 1);

    // Reading in the filename, but since the character limit is 100, you have to consider the extension. So I take the length of the extension and subtract from the file name limit dynamically
    // Also dealing with new line characters that can come with fgets
    fgets(filename, MAX_FILENAME - strlen(EXTENSION), stdin);
    filename[strcspn(filename, "\n")] = 0;
    strcat(filename, EXTENSION);

    // Check if file exists and only do the below operations if it exists. Open the file in read binary mode for this assignment
    FILE *file = fopen(filename, "rb");
    if (file)
    {
        fclose(file);
        char userFileChoice;
        printf("File %s already exists. Do you want to overwrite the filename (o), change the filename (c), or quit (q)?", filename);
        scanf(" %c", &userFileChoice);
        getchar();

        if (userFileChoice == 'q')
        {
            return NULL;
        }
        else if (userFileChoice == 'c')
        {
            printf("Enter a new filename without an extension please: \n");
            fgets(filename, MAX_FILENAME - strlen(EXTENSION), stdin);
            filename[strcspn(filename, "\n")] = 0;
            strcat(filename, EXTENSION);
        }
    }

    return fopen(filename, "wb");
}

void calculateAvgAllVals(DataSet *dataSet)
{
    double sum = 0.0;
    for (int i = 0; i < dataSet->numOfDoubles; ++i)
    {
        sum += dataSet->dataArr[i];
    }
    dataSet->avgAllVals = sum / dataSet->numOfDoubles;
}

/*
HW #13, Nolan Stutelberg
Enter a new filename without an extension (<20 characters)
or press [Enter] to use the default name:

File .xxx already exists. Do you want to overwrite the filename (o), change the filename (c), or quit (q)?c
Enter a new filename without an extension please:
MyFile

Wrote Dataset #1 to MyFile.xxx: 1624 bytes
The set contains 200 points, the avgAllVals is 10.2492

Wrote Dataset #2 to MyFile.xxx: 3224 bytes
The set contains 400 points, the avgAllVals is 10.4894
*/