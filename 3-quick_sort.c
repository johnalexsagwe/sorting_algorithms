#include "sort.h"
/**
 * swap - Swaps elements of an array
 * @array: The array
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}
/**
 * lomuto_partition - Partitions an array using Lomuto scheme.
 * @array: The array to be partitioned.
 * @low: The index to start from.
 * @high: The index of the last element.
 * @size: The size of the array.
 * Return: The pivot index.
 */
int lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(array, i, high);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_helper - Implements quick sort and maintains the original array.
 * @array: The array.
 * @low: The starting point.
 * @high: The end point.
 * @size: The size of the array.
 */
void quick_sort_helper(int *array, size_t low, size_t high, size_t size)
{
	int pivot_index;

	if (low >= high)
		return;
	pivot_index = lomuto_partition(array, low, high, size);
	if (pivot_index > 0)
		quick_sort_helper(array, low, pivot_index - 1, size);
	quick_sort_helper(array, pivot_index + 1, high, size);
}
/**
 * quick_sort - Sorts array using Lomuto partition scheme (quicksort)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
