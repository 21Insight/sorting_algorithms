#include "sort.h"
/**
 *bubble_sort - function that sorts an array
 *
 *@array: array to be sorted
 *@size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, tmp;

	if (array != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 1; j < size - i; j++)
			{
				if (array[j - 1] > array[j])
				{
					tmp = array[j - 1];
					array[j - 1] = array[j];
					array[j] = tmp;
					print_array(array, size);
				}
			}
		}
	}
}
