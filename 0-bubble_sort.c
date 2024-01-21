#include "sort.h"

/**
 * bubble_sort - the bubble sorting algorithm
 * @array: the unsorted array
 * @size: the size of the unsorted array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp, swap;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			swap = 1;
			print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
