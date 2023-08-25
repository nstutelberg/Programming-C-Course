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

/*

Using #define:
Advantages:

    Preprocessor Directives: #define is a preprocessor directive, which means the replacement of the defined value is done before the code is compiled. This can help improve performance in some cases because there's no runtime overhead for variable storage.

    Flexibility: You can use #define to define constants that are not limited to specific data types. For example, you can use it to define strings, expressions, or even macro functions.

Disadvantages:

    No Type Checking: #define does not respect data types. It's simply a textual replacement. This can lead to unexpected behavior if you use the constant in a way that doesn't match its intended data type.

    Limited Scope: Constants defined with #define are not scoped like variables. They are available throughout the entire file or until they are undefined, potentially leading to name clashes or confusion.

Using const:
Advantages:

    Type Safety: const enforces type safety. You explicitly define the type of the constant, reducing the chances of accidental misuse.

    Scoped: const constants are scoped, meaning they have a limited scope where they are visible and usable. This can help avoid naming conflicts.

    Compiler Optimization: Modern compilers can optimize code better when using const variables compared to #define macros. The constants can be stored more efficiently in memory.

Disadvantages:

    Runtime Storage: const constants consume memory during runtime. While this is usually negligible for small constants, it might matter in some embedded systems or performance-critical applications.

    More Syntax: const requires explicit syntax for defining the type and the value.

    For the specific example of #define Rate 0.5 vs const int Rate = 0.5;:

If Rate is meant to represent a constant integer value, then const int Rate = 0.5; is the correct choice because it enforces type safety and has better scoping.
If Rate is meant to represent a generic constant (not necessarily an integer), you might use #define Rate 0.5 for its flexibility, but you sacrifice type safety.
In modern C code, using const is generally preferred for defining constants whenever possible because it offers better type safety, scoping, and compatibility with the language's features.

*/