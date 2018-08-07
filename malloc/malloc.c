#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
    
    Do not just use the `strdup` function from the standard library.
*/
char *string_dup(char *src)
{
    int len = string_length(src);
    printf("len of src %d\n", len);
    char *duplicate = malloc(len + 1);
    int index = 0;
    while(src[index] != '\0')
    {
        duplicate[index] = src[index];
        index++;
    }
    duplicate[index] = '\0';
    return duplicate;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    `n` is the number of bytes to copy. You may want to cast the input 
    pointers to char pointers first before performing the copying. 
    
    Do not just use the `memcpy` function from the standard library.
*/
void *mem_copy(void *dest, const void *src, int n)
{
    int *int_dest = dest;
    int *numbers = src;
    for(int i = 0; i < n / sizeof(int); i++)
    {
        *int_dest = numbers[i];
        int_dest++;
    }
    int_dest -= n / sizeof(int);
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    return 0;
}
#endif
