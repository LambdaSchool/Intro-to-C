#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int length = 0;
    do
    {
        length++;
    } while (s[length] != '\0');
    return length;
    // alternative solution
    // int count = 0;
    // while (s[count] != '\0')
    //     count = count + 1;
    // return count;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int reverse = string_length(s);
    int i = 0;
    do
        rv[--reverse] = s[i++];
    while (s[i] != '\0');
    rv[i] = '\0';
    return rv;
    // alternative solution
    // int y, len;
    // len = string_length(s);
    // y = 0;
    // for (int x = len - 1; x >= 0; x--)
    // {
    //     rv[y] = s[x];
    //     y++;
    // }
    // rv[y] = '\0';
    // return rv;
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
