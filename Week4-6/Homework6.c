// HW #06, Nolan Stutelberg
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
# define NAVGS 6

// Declaring function prototypes
int randIntGenerator();
double randDblGenerator();

int main() {

    // Set up the random number generator
    srand((unsigned int) time(0));

    printf("HW #06, Nolan Stutelberg\n\n");
    printf("Set #  N Points  Average\n");
    printf("=====  ========  =======\n");
    
    // Initialize max_avg to store the largest max. Have to set to the lowest possible value so that no value will be less than this
    // This makes it so the next average we calculate is guaranteed to be larger than this initialized value
     double maxAvg = -DBL_MAX;

    // Start at set 1 since we are going from 1 to 6 sets, and incrementing the row number on each loop. populate the row with a random number and keep track of the current sum of numbers
    // Keeping track of the sum so that you can take the sum and divide by current number to have a running average
    for(int set = 1; set <= NAVGS; set++) {
        int num = randIntGenerator();
        double sum = 0.0;

        // Inner loop here to get the double value back and add it to the running sum
        for(int i = 0; i < num; i++) {
            sum += randDblGenerator();
        }

        double avg = sum / num;

        // Set the width specifiers so the data is always aligned
        printf("  %-7d %-6d %-.3f\n", set, num, avg);

        // Only overwrite the highest average if the current average surpassed it
        if(maxAvg < avg) {
            maxAvg = avg;
        }
    }

    printf("\nThe maximum average was -> %.3f\n", maxAvg);

    return 0;
}

int randIntGenerator() {
    int randNum = rand() % 46 + 5;
    return randNum;
}

double randDblGenerator() {

    double x = rand() * -10.0 / RAND_MAX;
    return x;
}


/*

HW #06, Nolan Stutelberg

Set #  N Points  Average
=====  ========  =======
  1       37     -4.234
  2       39     -4.947
  3       49     -5.156
  4       46     -4.674
  5       38     -6.121
  6       17     -5.266

The maximum average was -4.234

*/

/*

Test Plan (excluding tests from previous homework):

    1. Make sure that the sets are always from 1 to 6 and never lower or higher. Since the 6 is hardcoded as a defined constant
        - NAVGS is set to 6 with `# define NAVGS 6`, and the loop iterates only up to NAVGS, which is 6 -> `for(int set = 1; set <= NAVGS; set++)`

    2. Ensure that the averages are always negative due to the nature of the randDblGenerator() function.
        - Executed the code 5 times and checked that the values were always negative
        - Also see this code -> `double x = rand() * -10.0 / RAND_MAX;`. rand() only returns positive values, and multiplying a posititve by a negative returns a negative.
    
    3. Confirm that the for loop will exit
        - Running the program doesn't stall or wait for user input. The execution completes fully when the program is run
    
    4. Confirm that the max average has been returned at the end of the code
            1       40     -4.933
            2       8      -4.370
            3       35     -4.834
            4       28     -5.075
            5       6      -2.472
            6       28     -4.259
        - Through a visual check, the max average here is -2.472, and that was what was returned at the end of the code -> `The maximum average was -> -2.472`

    5. Confirm that spacing will always stay consistent
        - Since there is no user input and the random values can not get higher than the set value, the spacing will always stay consistent
        - The spacing is also set with a width specifier here -> `printf("  %-7d %-6d %-.3f\n", set, num, avg);`. 
        - The first column will only ever be 1 through 6, which is 1 digit. The second column will only be 5 through 50, which is at max 2 digits. Last column will be at max 1 digit then 3 digits after the decimal point, as set by the width specifier

    6.  Confirm that the number of data points will always be in the range 5-50.
        - Looking at the code, `int randNum = rand() % 46 + 5;` -> the `% 46` part ensures that the number generated will be between 0 and 45, but we set the endpoint to 46 to make sure you are including 45
        - Then add 5 to that result to shift the range from 5 to 50. So every number generated will be in this range
        - I could make a unit test that would iterate through the randIntGenerator function and store the min and max values, only overwriting the value if the current value is lower/higher depending on whether you want min/max

        - Ex: 
            if(maxNum < randNum) {
                maxNum = randNum;
            }
            if(minNum > randNum) {
                minNum = randNum;
            }

    7. Confirm the averages are being calculated correctly
        - Could manually sum the values and divide by the count to get the avg
            - Here are the first two rows for the sample output
                1       40     -4.933     -> Sum = -197.32 | Manual Avg = -197.32 / 40 = -4.933 | Program Avg = -4.933 -> Match
                2       8      -4.370     -> Sum = -34.96 | Manual Avg = -34.96 / 8 = -4.370 | Program Avg = -4.370 -> Match
            - Since the first 2 averages match the program averages, it is a good test to show that the rest will also have a matching result
            - The sum values are in line with what would be generated from `double x = rand() * -10.0 / RAND_MAX;`, since this function returns a negative random number

*/