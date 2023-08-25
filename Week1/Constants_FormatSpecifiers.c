// Literal constants
// Unnamed constant used to specify data. It is coded as part of a statment using a constant format
// Ex: 3.5, 'c'

// Defined constants
// The prepreocessor command `define` is prefaced by the pound sign and it is used at the beginning of the program to define things globally
// Ex: #define PI 3.14159

// Memory constants
// Uses a c type qualifier `const` to indicate that the data cannot be changed
// Ex: const int Number = 5;

#include <stdio.h>
#define PI 3.14159

int main()
{
    const int Number = 5;
    printf("%f", PI);

    // Common Format Specifiers:

    // Integers
    printf("Integer: %d\n", 42); // %d for int

    // Unsigned Integers
    printf("Unsigned Integer: %u\n", 42); // %u for unsigned int

    // Octal and Hexadecimal
    printf("Octal: %o\n", 42);       // %o for octal
    printf("Hexadecimal: %x\n", 42); // %x for lowercase hexadecimal
    printf("Hexadecimal: %X\n", 42); // %X for uppercase hexadecimal

    // Floating-Point Numbers
    printf("Float: %f\n", 3.14159);   // %f for float
    printf("Double: %lf\n", 3.14159); // %lf for double

    // Characters
    printf("Character: %c\n", 'A'); // %c for char

    // Strings (char arrays)
    printf("String: %s\n", "Hello"); // %s for string

    // Pointer Addresses
    int x = 42;
    printf("Pointer: %p\n", &x); // %p for pointer address

    // Escape Characters
    printf("Newline: \\n\n"); // Use \\n for a newline

    return 0;
}