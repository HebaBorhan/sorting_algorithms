#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int low, int high);
void recursive_sort(int *array, size_t size, int low, int high);
/**
 * swap - Swap two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
/**
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme (last element as pivot)
 * @array: The array of integers
 * @size: The size of the array
 * @low: The starting index
 * @high: The ending index
 * Return: i (partition index)
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
int j, i = low;
int *pivot = &array[high];
for (j = low; j <= high; j++)
{
if (array[j] < *pivot)
{
if (i < j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
i++;
}
}
if (array[i] > *pivot)
{
swap(&array[i], pivot);
print_array(array, size);
}
return (i);
}
/**
 * recursive_sort - Implement the quicksort algorithm through recursion
 * @array: An array of integers to sort
 * @size: The size of the array
 * @low: The starting index
 * @high: The ending index
 */
void recursive_sort(int *array, size_t size, int low, int high)
{
int index;
if (high > low)
{
index = lomuto_partition(array, size, low, high);
recursive_sort(array, size, low, index - 1);
recursive_sort(array, size, index + 1, high);
}
}
/**
 * quick_sort - function that sorts an array of integers
 * @array: pointer to the first element of an integer array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
recursive_sort(array, size, 0, size - 1);
}
