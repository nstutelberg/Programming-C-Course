/**
 * Rule of thumb for using the asterisk is if you have an * in the parameter list, use the * whenever you use the variable within that function. Not always true but this is usually true
 * In the exchangeFunction below, since px and py have the asterisk, you usually want to use the asterisk within the function whenever these variables are used within the function
 *
 */

void exchangeFunction(int *, int *);

int main(void)
{
    // Initialize the variables that are going to be swapped
    int a = 5;
    int b = 7;

    printf("The current value of a is %d and the current value of b is %d\n", a, b);
    // Use the function by passing through the MEMORY LOCATIONS of the a and b variables, since exchangeFunction has a parameter list of * variables, meaning it takes addresses as arguments
    // The function will look into the memory locations of a and b and swap them
    exchangeFunction(&a, &b);
    printf("The new value of a is %d and the new value of b is %d", a, b);
    return -0;
}

// The function below is using the * to specify that we want to be changing the values at the address location
void exchangeFunction(int *px, int *py)
{
    // specify temp because this function is meant to replace the values of the 2 arguments that are passed into the function. temp is to store one so you can swap the other
    int temp;

    // Make the value at the px memory location equal to temp, and make the py value equal to px, then apply temp back to py so the swap is complete
    temp = *px;
    *px = *py;
    *py = temp;

    return;
}