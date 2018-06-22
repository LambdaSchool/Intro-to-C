#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{

    int c = *a;
    *a = *b;
    *b = c;
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    printf("count of string %d", i);
    return i;
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
    int i = 0;
    printf("this is %c\n", y[0]);
    while (y[i] != '\0')
    {
        x[i] = y[i];
        i++;
    };
    if (x[i] != '\0')
    {
        x[i + 1] = '\0';
    };
    printf("This is x: %s\n", x);
    printf("End of x is %c\n", x[i]);
    // return x;
    // while (*y)
    // {
    //     *x = *y;
    //     x++;
    //     y++;
    // }
    // *x = '\0';
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
    for (; *m == *n; m++, n++)
    {
        if (*m == '\0')
        {
            return 0;
        }
    }
    return *m - *n;
    // int i = 0;
    // int mlength = string_length(&m) - 1;
    // int nlength = string_length(&n) - 1;
    // int max = 0;
    // if (mlength > nlength) {
    //     max = mlength;
    // } else if (mlength < nlength) {
    //     max = nlength;
    // } else {
    //     max = nlength;
    // };

    // while (m[i] !)
    // return m - n;

    //    for (;i <= max; i++) {
    //        if (m[i] != n[i]) {
    //         return *m - *n;
    //        } else if (m[i] == n[i]) {
    //            return 0;
    //        } else {
    //            printf("next");
    //        }
    //    }
    //     printf("character of m %c and n %c", m[i], n[i]);
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
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));

    return 0;
}
#endif
