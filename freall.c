#include "monty.h"
#include <stdio.h>

/**
 * free_dlistint - function to free memory with doubly linked list elements
 * @head: pointer to head of the list
 * Return: Do not return
 */
void free_dlistint(stack_t *head)
{
	stack_t *currentno;

	currentno = head;
	while (currentno != NULL)
	{
		currentno = head->next;
		free(head);
		head = currentno;
	}
}
