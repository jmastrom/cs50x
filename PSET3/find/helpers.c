/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //Custom search algorithm function call. This passes variables to the custom search function and returns a boolean.
    //custom search functions can be found below, and are included in helpers.h. 
    return binarysearch(value, values, n);
}

//Binary search implementation
bool binarysearch(int value, int values[], int n)
{
    //Set variables and values for the top and bottom of array indexes
    int lower = 0;
    int upper = n - 1;
    
    //While loop cotingent upon length of the array. If array is only 1, then do nothing.
    while (lower <= upper)
    {
        //Steps for binary search: find middle, compare, divide array (top or bottom)
        
        //Find the middle
        int middle = (upper + lower) / 2;
        
        //Compare middle to value wanted
        if (values[middle] == value)
        {
            return true; 
        }
        //If middle value is less than value desired, then set lower search index to middle +1 for next iteration
        else if (values[middle] < value)
        {
            lower = middle +1;
        }
        //if middle value is more than value desired, then set upper search index to middle -1 for next iteration
        else if (values[middle] > value)
        {
            upper = middle -1;
        }   
    }
    return false;
}


/**
 * Sorts array of n values.
 */
 
   // sort the haystack
   // sort(haystack, size);
    
void sort(int values[], int n)
{
    return bubblesort(values, n);
}



//bubblesort implementation O(n^2) sorting algorithm
void bubblesort(int values[], int n)
{
    // bubble sort
    for(int k = 0; k < n - 1; k++)
    {
        // optimization: check if there are no swaps
        int counter = 0;
        
            for(int i = 0; i < n - 1 - k; i++)
            {
                if (values[i] > values[i+1])
                {
                    int temp = values[i];
                    values[i] = values[i+1];
                    values[i+1] = temp;
                    counter++;
                }
            }
         //optimization: if counter is NOT incremented break out of the function
         if (!counter)
            break;
      }
}
