#include <stdio.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    int length = strlen(y); /* we already have the pointers, the value is what length is taken from here */
    for(int i = 0; i < length; i++) {
        *x = *y; /* dereference operators so we are copying the values referred to by these pointers */
        x++; /* incrementing x should eventually point to the null entry */
        y++;
    }
    printf("%s\n%s", x, y);
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
    /* reference any memory address that is not null, i.e. contains a char value
    get the first instance of char 'c' with a dereference operator
    store 'c' value in another variable
    return a pointer to this variable
    */

    while(*str != '\0') {
        if(*str == c) { /* dereference operator to find 'c' rather than the address at which 'c' is stored */
            char *pointer_store = str;
            printf("%s", pointer_store);
            return pointer_store; /* testing this with both the value and the pointer */
        }
        str++;
    }
    return 0;
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
    /* create a variable that can reference needle, deference to find value
    same as previous function, search through all non-null entires
    while searching through haystack, increment both
    if we reach the end of the search via needle dereference (searching through values), return the first instance
    */

    char *pointer_store = needle;

    while(*haystack != "\0") {
        if(*haystack == *needle) { /* searching through non-null entries*/
            char *target = haystack;
            while(*needle == *haystack && *needle != '\0') {
                needle++;
                haystack++;
            }
            if(*needle == '\0') {
                return target;
            }
            needle = pointer_store;
        }
        haystack++;
    }
    return 0;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
