#include "sort.h"
/**
 * swap - function that swaps 2 integers in an array.
 * @array: array to swap.
 * @first: first index.
 * @second: second index.
 * Return: Nothing it is a void function.
 */
void swap(int *array, int first, int second)
{
	int tmp;

	tmp = array[first];
	array[first] = array[second];
	array[second] = tmp;

}
/**
 * array_partition - function that moves all the lowest elements to the left
 * and all the greater elements to the right acording to a pivot number.
 * @array: array to move.
 * @start: index to start to compare.
 * @end: end index of the comparation.
 * @size: size of the array.
 * Return: the index of the pivot number.
 */
int array_partition(int *array, int start, int end, size_t size)
{
	int pivotIndex = start;
	int pivot = array[end];
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			swap(array, i, pivotIndex);
			if (pivotIndex != i)
				print_array(array, size);
			pivotIndex++;
		}
	}
	swap(array, pivotIndex, end);
	if (pivotIndex != end)
		print_array(array, size);

	return (pivotIndex);
}
/**
 * sort - recursive function that sorts all the elements of an array
 * form lowest to highest using the quicksort algorithm.
 * @array: array to sort.
 * @start: start point to sort.
 * @end: index for ends the sort.
 * @size: size of the array.
 */
void sort(int *array, int start, int end, size_t size)
{
	int pivotIndex;

	if (start < end)
	{
		pivotIndex = array_partition(array, start, end, size);
		sort(array, start, pivotIndex - 1, size);
		sort(array, pivotIndex + 1, end, size);
	}
}
/**
 * quick_sort - function that sorts an array of integers
 * form lowest to highest using the quicksort algorithm.
 * @array: array to sort.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, (int)size - 1, size);
}
