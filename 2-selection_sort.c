#include "sort.h"

/**
 * selection_sort - a function that sorts in ascending order by selection
 * @array: array to be sorted
 * @size: number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	int aux;
	size_t i, j, i_min;

	for (i = 0; i < size - 1; i++)
	{
		i_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i_min])
				i_min = j;
		}
		if (i_min != i)
		{
			aux = array[i];
			array[i] = array[i_min];
			array[i_min] = aux;
			print_array(array, size);
		}
	}
}
