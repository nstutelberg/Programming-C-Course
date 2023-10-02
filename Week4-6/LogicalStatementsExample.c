#include <stdio.h>

int main(void) {
    
    int inputInt;
    printf("enter a number between one and 10: ");
    scanf("%d", &inputInt);

    if (inputInt < 6) {
        printf("this is a low number ");
    } else {
        printf("this is a high number ");
    }
    if (inputInt % 2 == 0) {
        printf("and is even\n");
    } else {
        printf("and is not even\n");
    }

    //nested if
    if (1 == 1) {
        if (1 == 1) {
            printf("\nthis is nested");
        }
    } else {
        printf("\nthis is not nested");
    }
}