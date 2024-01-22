#include "sort.h"

/**
 * cocktail_sort_list - the algorithm for cocktail sort
 * @list: the list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapp = 1;
	listint_t *current;

	if (!list || !*list)
		return;

	current = *list;
	while (swapp)
	{
		swapp = 0;
		for (; current->next != NULL; current = current->next)
			if (current->n > current->next->n)
			{
				swap_1(current, list);
				swapp = 1;
				print_list(*list);
			}
			else
				current = current->next;

		if (!swapp)
			break;
		swapp = 0;
		while (current->prev != NULL)
			if (current->n < current->prev->n)
			{
				swap_1(current->prev, list);
				swapp = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		
	}
}

/**
 * swap_1 - swaps two integers
 * @a: the first integer
 * @list: head of the list
 */
void swap_1(listint_t *a, listint_t **list)
{
	if (a == NULL || a->next == NULL || list == NULL || *list == NULL)
		return;

	if (a->prev != NULL)
		a->prev->next = a->next;
	else
		*list = a->next;
	a->next->prev = a->prev;
	a->prev = a->next;
	a->next = a->next->next;

	if (a->next != NULL)
		a->next->prev = a;
	a->prev->next = a;
}
