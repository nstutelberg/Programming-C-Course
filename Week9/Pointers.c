#include <stdio.h>

/**
 * When you specify `int x = 3;` and you call x, the compiler is not returning x, it is returning the data that is stored within x, since x on the backend is just a memory address. Pointers contain addresses,
 * not values. If you want to change the value of a variable in a function you want to pass through the address of the variable so you can edit the value of the variable at the MEMORY ADDRESS
 *
 * Specifying `*` on a variable is an indirect operator, and it is used to access the variable through the pointer. So if you want to get the value of x and not just the memory location, do `x*`
 *
 * *&x == x (because * is getting the actual value at the memory location of &x), but this is redundant because you can just do int x
 *
 *
 */

int main(void)
{
    // To use indirection operator, you first declare x and give a value to it. Then you declare p as a pointer variable that points to the address of the value of p
    // But the address of p does not have a value right now, so when you assign p the value of &x, you are saying p has the same address as x. And since x has been supplied the value of 5, the value of 5
    // is at the address of x, so now the value of p (*p), is 5
    int x;
    x = 5;
    int *p;
    p = &x;
    printf("%d", *p);

    // can also do it this way, where you skip the intermediate step and say that the value of p2 should be whatever is in the address of x2, which we said was 20
    int x2 = 20;
    int *p2 = &x2;
    printf("\n%d", *p2);
}