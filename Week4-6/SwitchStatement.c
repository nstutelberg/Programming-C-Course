#include <stdio.h>

/**
 * Just like scala with case statement. The `choice` variable determines what case statement you will be redirected to. Test it!
*/
int main(void) {
    int choice;

    printf("Enter a number (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You chose option 1.\n");
            break;
        case 2:
            printf("You chose option 2.\n");
            break;
        case 3:
            printf("You chose option 3.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}