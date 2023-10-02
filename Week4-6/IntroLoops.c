#include <stdio.h>

int main(void) {

    // Before starting the loop, want to set a counter and a sum value so the while loop stops eventually, and that the total sum is captured
    long sum = 0L;
    long num = 0L;
    int status = 1;
    printf("enter a number that you want to be summed, or enter q to quit");

    // set status to 1, because when a successful scanf happens and a valid long integer is entered, status will be 1, which evaluates the statement to true, and the loop is executed
    while (status == scanf("%ld", &num)) {
        sum += num;
        printf("the total sum is now %ld, continue entering numbers or press q to quit", sum);
    }

    long longSum = 0L;
    for (int i = 0; i < 10; i++) {
        longSum += i * 10;
        printf("rolling sum of multiplying the current index by 10 and aggregating is:  %ld \n", longSum);
    }
    return 0;
}
