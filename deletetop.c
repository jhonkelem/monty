#include "monty.h"
#include <stdio.h>

/**
 * delete_dnodeint_at_index - function to delete element of the list
 * @head: pointer to head of the list
 * @index: position to index
 * Return: 1 if it deletes or -1 if it fails
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int n = 0;
	stack_t *current;

	if (*head != NULL)
	{
		current = *head;
		if (index == 0)
		{
			if (current->next)
				current->next->prev = NULL;
			*head = current->next;
			free(current);
			return (1);
		}
		while (current != NULL)
		{
			/* printf("%d\n", h->n); */
			if (n  == index)
			{
				if (current->prev)
					current->prev->next = current->next;
				if (current->next)
					current->next->prev = current->prev;
				free(current);
				return (1);
			}
			current = current->next;
			n++;
		}
	}
	return (-1);
}
