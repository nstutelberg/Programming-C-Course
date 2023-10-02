#include <stdio.h>

int main(void) {

//basic prefix
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int resultGenericPrefix = (a != b) ? ++c : ++d;
    // See how the ressult is 4 for both the result and for c. This is because with prefix increment, the values are incremented first, then the result is assigned.
    printf("\nresult is: %d, c is now: %d, and d is now: %d\n", resultGenericPrefix, c, d);

//basic postfix
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    int resultGenericPostfix = (a != b) ? c++ : d++;
    // See how the result is 3 but the value is c is showing as 4. This is because with a postfix, c was assigned to `resultGeneric` as its original value of 3, then it incremented
    printf("\nresult is: %d, c is now: %d, and d is now: %d\n", resultGenericPostfix, c, d);

//prefix with if/else and math included
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    int resultPrefix = (a == b) ? ++c + 1 : ++d + 1;
    // See now how the result changed to 6 but the variables had their values changed just the same
    // Since there is a prefix increment here, first the value is incremented, then it is used in the operation. So d is first incremented from 4 to 5, then 1 is added, so the result is 6
    printf("\nresult is: %d, c is now: %d, and d is now: %d\n", resultPrefix, c, d);

// postfix with if/else and math included
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    int resultPostfix = (a == b) ? c++ + 1: d++ + 1;
    // Note that since a is not equal to b, that `d++` was executed, and it was incremented by 1 and went from 4 to 5.
    // But see because of the postfix expression, that the pre-increment value was used in the math operation. Only after the expression completes does the variable change
    // The final result is 5 because the operation was 4 + 1. But after expression completes, d is incremented to 5
    printf("\nresult is: %d, c is now: %d, and d is now: %d\n\n", resultPostfix, c, d);







}