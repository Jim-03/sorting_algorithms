#include "sort.h"

/**
 * quick_sort - the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * lomuto_partition - the lomuto partiton scheme
 * @arr: the array to be sorted
 * @low: the lowest index
 * @high: the highest index
 * @size: the size of the array
 * Return: the index of pivot
 */
size_t lomuto_partition(int *arr, size_t low, size_t high, size_t size)
{
	int pivot;
	unsigned int k, i, j;

	pivot = arr[high];
	i = low - 1;

	for (j = low; j < high; j++)
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);

			for (k = 0; k < size; k++)
			{
				printf("%d", arr[k]);
				if (k < size - 1)
					printf(", ");
			}
		}
	swap(&arr[i + 1], &arr[high]);
	for (k = 0; k < size; k++)
	{
		printf("%d", arr[k]);
		if (k < size - 1)
			printf(", ");
	}
	printf("\n");
	return (i + 1);
}

/**
 * quick_sort_recursive - the recursive loop for quick sort
 * @arr: array to be sorted
 * @low: lowest index
 * @high:highest index
 * @size: size of array
 */
void quick_sort_recursive(int *arr, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(arr, low, high, size);
		quick_sort_recursive(arr, low, pivot - 1, size);
		quick_sort_recursive(arr, pivot + 1, high, size);
	}
}

/**
 * swap - swaps two integers
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
