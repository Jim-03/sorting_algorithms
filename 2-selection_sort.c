#include "sort.h"

/**
 * selection_sort - the selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, idx;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[idx])
				idx = j;
		if (idx != 1)
		{
			temp = array[i];
			array[i] = array[idx];
			array[idx] = temp;
			for (j = 0; j < size; j++)
			{
				printf("%d", array[j]);
				if (j < size - 1)
					printf(", ");
			}
			printf("\n");
		}
	}
}
