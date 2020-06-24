#include "sort.h"
/**
 *insertion_sort_list - function that sort a list
 *
 *@list: head to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *insert, *where, *insert_p, *insert_n, *where_p, *aux;
	const listint_t *print;
	int i, w = 0;

	aux = *list;
	for (i = 0; aux != NULL; aux = aux->next, i++)
	{
		printf("aux: %i, aux next: %i", aux->n, aux->next->n);
		where = aux;
		insert = aux;
		for (w = i; w > 0 && where->n < insert->n; where = where->prev, w--)
			{
				printf("where: %i\n", where->prev->n);
				if (insert->n < where->n)
				{
					printf("where: %i:", where->n);
					printf("insert: %i:", insert->n);
					insert_n = insert->next;
					insert_p = insert->prev;
					where_p = where->prev;
					if (insert_n != NULL)
						insert_n->prev = insert_p;
					insert_p->next = insert_n;
					insert->next = where;
					insert->prev = where_p;
					if (where_p != NULL)
						where_p->next = insert;
					else
						*list = insert;
					where->prev = insert;
					print = *list;
					print_list(print);
				}
			}
	}
}
