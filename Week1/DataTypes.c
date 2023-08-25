// Void data types are useful because they are used when a function takes no parameters or gives no return value. The pointer points to nothing. Just void and empty

/**
 * Float is only useful over double because float takes 4 bytes of memory, and double takes 8 bytes. Every time you use float, it converts to a double with any math operations
 * The benefit of float is if you are storing a ton of data, it takes up half the space. Just note that the run time will be longer because it needs to convert the data to double and then back to float
 **/

// Strings are actually broken down from "abc" to "a", "b", "c", "\0" (null character). So a string always ends with a null character to define the end of the string

#include <stdio.h>

int main(void)
{
    printf("this method is void");
}
