#include "sort.h"
/**
 * selection_sort - Sorts an array using selection sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int minimum, temp;

	for (i = 0; i < size; i++)
	{
		minimum = array[i];
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < minimum)
			{
				minimum = array[j];
				min_index = j;
			}
		}
		if (min_index != i && array[i] != minimum)
		{
			temp = array[i];
			array[i] = minimum;
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
