#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    /* Initialize an integer variable at 0 */
    int index = 0;

    /* Loop through the string. While the given is not the nul character, icrement the index variable */
    while (s[index] != '\0') {
        index ++;
    }
    /* return the index */
    return index;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    /* Initialize an integer variable named 'length' and set 'length' equal to the return from string_length(s) */
    int length = string_length(s);

    /* Initialize an integer variable 'end' and set it equal to the length of string - 1 (the last elemnt in the array). Then initialize an integer variable 'start' and set it to 0 */
    int end = length - 1;
    int start = 0;

    /* While the counter for 'start' is less than or equal to the length of the string, 
    set the element at the index of 'start' in the rv array to equal the element at the index of 'end' in the s array
    increment the 'start' counter and decrement the 'end' counter */
    while (start <= length)
    {
        rv[start] = s[end];
        start ++;
        end --;
    }
    /* return the rv array */
    return rv;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
