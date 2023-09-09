#include <stdio.h>

// Always have to specify the prototypes of the functions before you do anything
int adder(int *pNum);
int subtracter(int *pNum);

int main(void)
{
    int startingNum = 10;

    int postAddVal = adder(&startingNum);
    int postSubVal = subtracter(&postAddVal);

    printf("the starting number was: %d, the post addition value was: %d, and the post subtraction value was: %d", startingNum, postAddVal, postSubVal);

    return 0;
}

int adder(int *pNum)
{
    int addedNum = *pNum + 20; // Dereference the pointer to modify the value it points to
    int resultTimesTwo = addedNum * 2;
    return resultTimesTwo;
}

int subtracter(int *pNum)
{
    int subtractedNum = *pNum - 20; // Dereference the pointer to modify the value it points to
    int resultDivByTwo = subtractedNum / 2;
    return resultDivByTwo;
}
