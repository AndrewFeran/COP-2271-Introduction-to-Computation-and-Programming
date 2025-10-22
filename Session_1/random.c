/*
    10/21/2025

    The goal is to create a program that will
    1. ask the user for an upper and lower bound
    2. generate a random number within these bounds (inclusive)
    3. do something with the result

    We should have a function called generateRand that takes:
    an integer for lower bound as first argument
    an integer for upper bound as second argument
    returns randomly generated integer in that range (inclusive)
*/
#include <iostream>
// don't forget to import necessary libraries
#include <time.h>

int generateRand(int lower, int upper) {
    // random number in (L, U) = L + (rand() % (U-L+1))
    return lower + (rand() % (upper-lower+1));
}

// main program for testing our function
int main() {
    // remember to give random function a different seed each time we run
    srand(time(NULL));

    // initialize our variables for lower and upper bounds
    int L, U = 0;
    puts("Please enter the lower bound followed by the upper bound, seperated by space: ");
    scanf("%d %d", &L, &U);

    int num = generateRand(L, U); // lets get our first number

    // while our random number is not at the upper bound, let's keep going
    while (num != U) {
        switch (num) {
            case 59:
                // this is a special case... if num is 59: skip and print new line
                puts("");
                break;
            default:
                // otherwise we print the number as usual
                printf("%d ", num);
        }
        num = generateRand(L, U); // generate a new random number at each iteration
    }

    // finally print the last number that was generated
    printf("%d ", num);

    return 0;
}