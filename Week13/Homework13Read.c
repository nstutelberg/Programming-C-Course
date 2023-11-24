// HW #13, Nolan Stutelberg
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

FILE *openRdBinaryFile(char *fileName);

int main()
{
    printf("HW #13, Nolan Stutelberg Part 2\n");
    char fileName[MAX_FILENAME] = {0};
    FILE *file = openRdBinaryFile(fileName);

    if (file)
    {
        // Read in the size of the first dataset and use fseek to move to the second set of data
        int firstDatasetSize;
        fseek(file, sizeof(int), SEEK_SET);
        fread(&firstDatasetSize, sizeof(int), 1, file);
        fseek(file, sizeof(DataSet) + sizeof(double) * firstDatasetSize, SEEK_SET);

        // Now read the second dataset
        DataSet myVLA;
        fread(&myVLA, sizeof(DataSet), 1, file);

        // Allocate memory for data array and read in the dataset data
        myVLA.dataArr = (double *)malloc(myVLA.numOfDoubles * sizeof(double));
        fread(myVLA.dataArr, sizeof(double), myVLA.numOfDoubles, file);

        double calculatedavgAllVals = 0;
        for (int i = 0; i < myVLA.numOfDoubles; ++i)
        {
            calculatedavgAllVals += myVLA.dataArr[i];
        }
        calculatedavgAllVals /= myVLA.numOfDoubles;

        // Print all the results
        printf("Read from file: %s\n", fileName);
        printf("Dataset #%d: %lu bytes\n", myVLA.dataSetNum, sizeof(DataSet) + sizeof(double) * myVLA.numOfDoubles);
        printf("Number of Data Points: %d\n", myVLA.numOfDoubles);
        printf("avgAllVals from file: %.4f\n", myVLA.avgAllVals);
        printf("avgAllVals calculated: %.4f\n", calculatedavgAllVals);
        printf("The averages are %s\n", (myVLA.avgAllVals == calculatedavgAllVals) ? "equal" : "not equal");

        // Memory management to free the memory and close the file
        fclose(file);
        free(myVLA.dataArr);
    }
    return 0;
}

FILE *openRdBinaryFile(char *fileName)
{
    // Creating the complete file name
    printf("Enter a new filename without an extension (<%d characters)\nor press [Enter] to use the default name:\n", MAX_FILENAME - strlen(EXTENSION) - 1);
    fgets(fileName, MAX_FILENAME - strlen(EXTENSION), stdin);
    fileName[strcspn(fileName, "\n")] = 0;
    strcat(fileName, EXTENSION);

    return fopen(fileName, "rb");
}

/*
Sample Output:

HW #13, Nolan Stutelberg Part 2
Enter a new filename without an extension (<20 characters)
or press [Enter] to use the default name:
MyFile
Read from file: MyFile.xxx
Dataset #2: 3224 bytes
Number of Data Points: 400
avgAllVals from file: 10.4894
avgAllVals calculated: 10.4894
The averages are equal
*/