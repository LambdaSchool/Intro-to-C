#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the
    address it's referring to) or the value at the address it's
    pointing at.
*/
void swap(int *a, int *b)
{
    int foo = *a;

    *a = *b;
    *b = foo;
}

/*
    Searches the input string `str` for the first instance of the
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{

    while (*str)
    {
        if (*str == c)
            return str;
        str++;
    }
    return NULL;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its
    end to terminate it properly.

    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    while (*y != '\0')
    {
        *x = *y;
        x++;
        y++;
    }

    *x = *y;
}

/*
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.

    For example, given matching strings, this function should
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.

    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    int difference;
    while (*m != '\0' || *n != '\0')
    {
        difference = *m - *n;
        if (difference != 0)
            break;
        m++;
        n++;
    }

    difference = *m - *n;
    return difference;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`.

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    char *start = find_char(haystack, needle[0]);
    printf("this is is start:%s, \n", start);
    for (int i = 0; needle[i] != '\0'; i++)
    {
        if (start[i] != needle[i])
        {
            return NULL;
        }
    }
    return start;
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";
    char buffer[1024];

    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Comparison is %d\n", string_compare(hello, world));

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
