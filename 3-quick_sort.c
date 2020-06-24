#include "sort.h"


/**
 * partition - recursively does Lomuto partition
 * @array: the array to be sorted
 * @start: the first element of the array
 * @end: the pivot for the array
 */
void partition(int *array, size_t start, size_t end)
{
	(void)array;
	(void)start;
	(void)end;
}


/**
 * quick_sort - a function that sorts an array by quick sort
 * @array: the array to be sorted
 * @size: number of elements that the array has
 */
void quick_sort(int *array, size_t size)
{
	size_t i, index, aux;
	int pivot;

	pivot = array[size - 1];
	index = 0;
	for (i = 0; i < size; i++)
	{
		if (pivot >= array[i])
		{
			aux = array[i];
			array[i] = array[index];
			array[index] = aux;
			index++;
		}
	}
}
