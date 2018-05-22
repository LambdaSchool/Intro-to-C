#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int fizzbuzz(int n)
{
    // static int counter = 0;
    // while (n > 0) {
    // if((n==3) && (n==5)) {
    //     printf("FizzBuzz");
    //     continue;
    // }
    // else if(n==3) {
    //     printf("Fizz");
    //     continue;
    // } else if (n==5) {
    //     printf("Buzz");
    //     continue;
    // } else {
    //     counter++;
    //     n--;
    // }

    
    // }

    // printf("%d" ,counter);

    // return counter;
int counter = 0;
    int i;
    for(i = 1; i <= n; i++) {
        if((i % 3 == 0) && (i % 5 == 0)) printf("\nFizzBuzz");
        else if(i % 3 == 0) printf("\nFizz");
        else if(i % 5 == 0) printf("\nBuzz");
        else counter++;
    }
    printf("\n%d", counter);
    return counter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(3);

    return 0;
}
#endif
