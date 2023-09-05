/* %d - Integer */        //-------------> -40 (signed integer)
/* %f - Floating-point */ // ------------> 20.0f
/* %c - Character */      // ------------> 's'
/* %s - String */
/* %x - Hexadecimal */
/* %o - Octal */
/* %u - Unsigned integer */ // ----------> 0x44
/* %ld - Long integer */    // ------------> 1000L
/* %lu - Unsigned long integer */
/* %lld - Long long integer */
/* %llu - Unsigned long long integer */
/* %e - Scientific notation (exponential) */
/* %g - Shortest representation (either %f or %e) */
/* %p - Pointer address */
/* %lf - Double floating-point */
/* %Lf - Long double floating-point */ // -------> 2.9e05L
/* %t - ptrdiff_t */
/* %zu - size_t */
/* %I64d - Microsoft-specific 64-bit integer */
#include <stdio.h>

int main(void)
{
    char myString[] = "hello how are you";
    printf("%s", myString);

    // notice how the number `34.` has 3 spaces. But I set minimum width to 10, so it pads that with 0's. And the `2` on the right means two decimal places
    // notice what happens when you use a plus or a minus, it changes the alignment and adds `+` and `-`
    float floatExample = 34.98739;
    printf("\n%10.2lf", floatExample);   // normal print no specifier
    printf("\n%-10.2lf", floatExample);  // left align with `-`
    printf("\n%+10.2lf", floatExample);  // add the + or - sign before the number
    printf("\n%+-10.2lf", floatExample); // same as above but left align
    printf("\n%-+10.2lf", floatExample); // same as above but change order of `-` and `+` symbol
    printf("\n%010.2lf", floatExample);  // create leading zeros instead of empty spaces

    // for scanf, you need to use a pointer (&), because c reads in the user input,and either throws it away, or stores it at the memmory address
    int myInt;
    char myChar;
    printf("\n\n");
    scanf("%d %c", &myInt, &myChar);
    printf("%d %c", myInt, myChar);
    return 0;
}