#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * selection_sort - sorts array of int. in ascending order using selection sort
 * @array: pointer to the first element of an integer array
 * @size: size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
    int temp;
    size_t i, j, min_index;

    if (size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            temp = array[min_index];
            array[min_index] = array[i];
            array[i] = temp;
        }
    
        print_array(array, size);
    }
}
