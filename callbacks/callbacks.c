#include <stdio.h>
#include <stdlib.h>
#include "callbacks.h"
#include "lib.h"

/*
    Implement the callback that will be passed to your bubble_sort function to sort 
    the elements in ascending numerical order.
*/
int sorted_order(int a, int b)
{
    return a - b;
}

/*
    Implement the callback that will be passed to your bubble_sort function to sort
    the elements in descending (reverse) numerical order.
*/
int reverse_order(int a, int b)
{
    return b - a;
}

/*
    Receives an array of numbers to be sorted, the number of elements in the array,
    and a callback that specifies the order in which the numbers will be sorted.
    Your function should allocate memory to hold the sorted data and return the 
    sorted data. Call the callback as you would any other function. 
*/
// int *bubble_sort(int *numbers, int n, compare_cb cmp)
// {
//     int *target = (int *) malloc(n * sizeof(int));
//     // mem_copy(target, numbers, n * sizeof(int));
//     for (int i = 0; i < n; i++) target[i] = numbers[i];

//     for (int i = 0; i < n; i++) {
//         for (int j = 1; j < n - 1; j++) {
//             if(cmp(target[j - 1], target[j]) > 0)
//                 swap(&target[j], &target[j - 1]);
//         }
//     }

//     return target;
// }

int *bubble_sort(int *numbers, int n, compare_cb cmp)
{
    int *target = malloc(n * sizeof(int));
    mem_copy(target, numbers, n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
             if (cmp(target[j], target[j + 1])> 0) {
                swap(&target[j], &target[j + 1]);
            }
        }
    }

    return target;
}

// int *bubble_sort(int *numbers, int n, compare_cb cmp)
// {
//  int *arr = (int *)malloc(n*sizeof(int));
//  //copy all the data in our arr
//  for(int i=0; i<n; i++) arr[i] = numbers[i];
//  for(int i=0; i<n; i++){
//      for(int j=1; j<n-i; j++){
//          if( cmp(arr[j-1],arr[j])>0)
//             swap( &arr[j],&arr[j-1]);
//      }
//  }

// 100,5, 4, 98, i=0,j=1, 5 100, 4,98, i=0,j=2, 5,4,100,98, i=0,j=3 5,4,98,100, i=1,j=1 4,5,98,100,  
//  return arr;
// }


#ifndef TESTING
int main(void)
{
    int arr[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int count = sizeof(arr) / sizeof(arr[0]);
    int *sorted_arr;

    //sorted_arr = bubble_sort(arr, count, sorted_order);
    sorted_arr = bubble_sort(arr, count, reverse_order);

    for (int i = 0; i < count; i++)
    {
        printf("%d ", sorted_arr[i]);
    }

    printf("\n");

    return 0;
}
#endif