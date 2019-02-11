#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int counter = 0;
    for (int i = 0; i < 100; i++)
    {
        if (s[i] == '\0')
        {
            break;
        }
        else
        {
            counter++;
        }
    }
    return counter;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char rv[], char s[])
{
    int length = string_length(s);
    int j = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        rv[j] = s[i];
        printf("this is the %d index and the character of rv: %c \n", j, rv[j]);
        j++;
        if (i == 0)
        {
            rv[j + 1] = '\0';
            printf("this is rv: %s \n", rv);
        }
    }

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
