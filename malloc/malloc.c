#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
    
    Do not use the `strdup` function from the standard library.
*/

// a b c d e 5

char *string_dup(char *src)
{
  int len = string_length(src); // finds length of string
  char *duplicate = malloc(len); // allocates memory based on string length

  for (int i = 0; i < len; i++) // loop based on src's length
  {
    *(duplicate+i) = *(src+i); // use pointer arithmetic to move positions and copy
  }

  *(duplicate + len) = '\0'; // terminate
  return duplicate; // returns the pointer of the duplicate string
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    `n` is the number of bytes to copy. You may want to cast the input 
    pointers to char pointers first before performing the copying. 
    
    Do not use the `memcpy` function from the standard library.
*/
void *mem_copy(void *dest, const void *src, int n)
{
  char *pSrc = (char*) src; // typecast src to char pointer, per instructions
  char *pDest = (char*) dest; // typecast dest to char pointer to do pointer arithmetic

  for (int i = 0; i < n; i++) // loop over total number of bytes amount
  {
    *(pDest+i) = *(pSrc+i); // copy to destination with src
  }
  
  return 0;
}

/*
    Given a pointer that `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 

    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?

    Do not use the `realloc` function from the standard libary.
*/
void *resize_memory(void *ptr, int old_size, int new_size)
{
  // THREE
  // "`resize_memory` should return a pointer to a block of memory of the specified `new_size`, 
  // and that block should contain as much of the data from the old block as it can fit." -per Sean

  // if new size is bigger, it only writes all of old size into it and stops when it gets to new size end
  // if new size is smaller, it writes only enough old size that fits and breaks there
  // there are 2 terminating condition in this solution: "i < old_size" and "i == new_size", whichever comes first
  // we use char type because tests uses letters

  // ^new_size
  // 1 2 3 4 5 6 7 8 9 10
  // ^old_size

  char *pOld = ptr; // stores the address of old ptr
  char *pResized = (char *) malloc(new_size); // make new malloc with new_size

  for (int i=0; i < old_size; i++) // loop over the old size since we want to write it to new pResized
  {
    if (i == new_size) break; // if reaches end of new malloc, exit loop
    pResized[i] = pOld[i]; // write old data into new malloc
  }

  return pResized;

  // TWO
  // char *pOld = ptr; // stores the address of ptr
  // char *pNew = (char *) malloc(new_size); // make new malloc
  
  // if (new_size > old_size)
  // {
  //   for (int i=0; i < new_size; i++) // loop over new malloc since new_size is bigger
  //   {
  //     if (i == old_size) break; // if reaches old malloc size end, exit loop
  //     pNew[i] = pOld[i]; // write old data into new malloc
  //   }
  // }
  // else if (old_size > new_size)
  // {
  //   pNew = (char *) malloc(old_size); // allocate more memory if old size is bigger
  //   for (int i=0; i < old_size; i++) // loop over old malloc since old_size bigger
  //   {
  //     if (i == new_size) break; // if reaches new malloc size end, exit loop
  //     pNew[i] = pOld[i]; // "contain as much of the data from the old block as it can fit" -per Sean
  //   }
  //   return pNew; // return modified pNew
  // }
  // return pNew;

  // ONE
  // if (old_size > new_size)
  // {
  //   for (int i = 0; i < old_size; i++)
  //   {
  //     if (i == new_size)
  //     {
  //       break;
  //     }
  //     p1[i] = p0[i];
  //     // p0[i] = p1[i];
  //   }
  // }
  // return p1;

  // if (new_size > old_size)
  // {
  //   p1 = (int *) malloc(new_size);
  //   for (int i = 0; i < new_size; i++)
  //   {
  //     p0[i] = p1[i];
  //   }
  //   return p0;
  // }
  // else if (new_size < old_size)
  // {
  //   p1 = (int *) malloc(old_size);
  //   for (int i = 0; i < old_size; i++)
  //   {
  //     if (i == new_size)
  //     {
  //       break;
  //     }
  //     p1[i] = p0[i];
  //   }
  //   return p1;
  // }
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

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);
    
    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0') {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    return 0;
}
#endif
