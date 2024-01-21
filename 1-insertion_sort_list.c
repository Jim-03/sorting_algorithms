#include "sort.h"

/**
 * insertion_sort_list - the insertion sort algortihm on a linked list
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c, *p, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	c = (*list)->next;
	while (c != NULL)
	{
		temp = c;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			p = temp->prev;
			if (temp->next != NULL)
				temp->next->prev = p;
			p->next = temp->next;
			temp->next = p;
			temp->prev = p->prev;
			p->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
		}

		c = c->next;
	}
}
