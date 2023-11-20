#include "sort.h"
/**
 * insertion_sort_list - Sorts a linked list using insertion sort.
 * @list: Pointer to the head of the list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted, *next_node, *current_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	unsorted = (*list)->next;
	while (unsorted)
	{
		next_node = unsorted->next;
		current_node = unsorted->prev;
		while (current_node != NULL && unsorted->n < current_node->n)
		{
			current_node->next = unsorted->next;
			if (unsorted->next != NULL)
				unsorted->next->prev = current_node;
			unsorted->next = current_node;
			unsorted->prev = current_node->prev;
			if (current_node->prev != NULL)
				current_node->prev->next = unsorted;
			else
				*list = unsorted;
			current_node->prev = unsorted;
			current_node = unsorted->prev;
			print_list(*list);
		}
		unsorted = next_node;
	}
}
