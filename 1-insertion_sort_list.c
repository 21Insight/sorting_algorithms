#include "sort.h"
/**
 * swap_nodes - function that swaps 2 nodes of a doubly linked list.
 * @list: double pointer to the double linked list head.
 * @curr: First node.
 * @nxt: Second node.
 * Return: Nothing it is a void function.
 */
void swap_nodes(listint_t **list, listint_t *curr, listint_t *nxt)
{
	listint_t *tmp = curr;

	/* tmp will be next to nxt */
	tmp->next = nxt->next;

	/* if tmp has a node next to */
	if (tmp->next != NULL)
		tmp->next->prev = tmp;

	/* nxt will be the first node */
	nxt->prev = tmp->prev;

	/* if nxt has a node behind it */
	if (nxt->prev != NULL)
		nxt->prev->next = nxt;

	/* else will be the head of the list */
	else
		*list = nxt;

	/* conecting themselves */
	tmp->prev = nxt;
	nxt->next = tmp;

	print_list(*list);
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: double pointer to the double linked list head.
 * Return: Nothing it is a void function.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *tmp = NULL;

	if (!list || !*list)
		return;

	curr = *list;
	while (curr->next != NULL)
	{
		if (curr->n > curr->next->n)
		{
			swap_nodes(list, curr, curr->next);
			tmp = curr;
			curr = curr->prev;
			while (curr->prev && curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
			}
			curr = tmp;
		}
		else
			curr = curr->next;
	}
}
