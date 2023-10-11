/**
 * There are different ways to sort arrays obviously.
 *
 * Selection sort divides a list into twoi sublists, sorted and unsorted. Every iterations, you search for the smallest element
 * in the list, and then compare that smallest value to the current value you are comparing against. So say if you have already sorted elements 1 and 2, then for element 3,
 * you will find the smallest element in the remaining unsorted part of the list and compare to element 3. If element 3 is smaller than the value that was found in the unsorted list, then list stays the same
 * and you move on. If there was a smaller value in the unsorted part of the array, then you replace the current element (element 3) with the smallest unsorted value, and move on to element 4.
 *
 * Bubble sort comparesadjacent elements, and if a smaller value is found, it is then compared 1-by-1 to every element in the list leading up to that point. So it does a bunch of comparisons between two elements,
 * and when the element reaches a point where the element it is being compared to is not larger, then you stop there and test the next element. It's called bubble sort because the element bubbles up to where
 * it should belong.
 *
 * Insertion sort is one of the most common sorting algorithms used by card sorting if you had a hand of cards. You keep track of all the numbers and their order in the sorted portion, then when you encounter
 * a new card, you just insert it at the correct poisition and shift all elements over to make room.
 */

#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;

        // Swap the found minimum element with the first element
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    bubbleSort(arr, n);
    printf("Sorted array using Bubble Sort: \n");
    printArray(arr, n);

    // Resetting array to unsorted form for next algorithm
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr2, n);
    printf("Sorted array using Insertion Sort: \n");
    printArray(arr2, n);

    // Resetting array to unsorted form for next algorithm
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr3, n);
    printf("Sorted array using Selection Sort: \n");
    printArray(arr3, n);

    return 0;
}