#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/

// #include <stdio.h>

// int main(void)
// {
// 	int x = 0;   // Set x to 0

// 	int *p = &x; // Set p to point to x, set to address of x

// 	*p = 3490;   // Set the thing that p points to to 3490

// 	printf("x is %d\n", x);  // 3490
// 	printf("x is %d\n", *p); // 3490 
// printf("p is %d\n", &p);
// printf("x is %d\n", &x);

// 	return 0;
// }


void swap(int* a, int* b)
{
    
    // int a;
    // int b;
    printf("before --- a: %d b: %d\n", *a, *b);
    int c = *a;
    *a = *b;
    *b = c;
    /*
    We got:
    a = 10;
    b = 20;
    We want:
    a = 20;
    b = 10;

    i
    *a = *b;
    // the value of a now is 20 
    *b = *a;
    // the value of b is still 20
    */

    printf("after --- a is %d\n", *a);
    printf("after --- b is %d\n", *b);
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

    for (int i = 0; i < strlen(str); i++) {

        if(str[i] == c)  {
            printf("The character %c was found.\n", str[i]);
        }
        else {
            printf("The character %c was not found at position %d. \n", str[i], str);
        }
    }
    return str;   
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary heres Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{

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
