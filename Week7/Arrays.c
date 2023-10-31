#include <stdio.h>
#include <stdlib.h>

/**
 * There are fixed length arrays and dynamic arrays in C. Fixed are most commonly used, and are defined to have a fixed length
 * If you want to pass an array into a function and don't change the array, you have to set to receive a constant array -> (const int myArray[])
 * Note that you cannot return an array in a C function but only a pointer to the array
 * 
 */


int* doubleArrayElements(const int* array, int size) {
    int* doubledArray = (int*)malloc(size * sizeof(int));
    if (doubledArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit the program immediately
    }
    
    for (int i = 0; i < size; i++) {
        doubledArray[i] = array[i] * 2;
    }

    return doubledArray; // returning a pointer to the dynamically-allocated array
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int array[n]; // declaring a variable-length array
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Calling the function
    int* doubledArray = doubleArrayElements(array, n);
    
    // Display the elements of the new array
    printf("Doubled elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", doubledArray[i]);
    }
    printf("\n");

    free(doubledArray); // deallocating the memory
    return 0;
}
