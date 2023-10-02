#include <stdio.h>


int main(void) {

    // Want to use ternary operator to apply a condition to assign a new value to a variable. 
    // syntax is -> newVar = (logical condition) ? what to assign if true : what to assign if false
    int x = 5;
    int y;

    printf("%d\n", y);
    y = (x != 5) ? y : -y;
    printf("%d\n", y);

    
}