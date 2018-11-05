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
int count = 0;

  for(int a = 1; a < n; a++){
    if(a%3==0 && a%5==0){
      printf("fizzbuzz\n");
      //printf("%d if 3\n",a);
    }
    else if(a%5==0){
      printf("buzz\n");
      //printf("%d if 5\n",a);
    }
    else if (a%3==0){
      printf("fizz\n");
      //printf("%d if both\n",a);
    }
    else
    {
      //return a;
      count = count + 1;

      printf("%d\n", count);
    }
  }
return count;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
