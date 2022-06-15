#include "monty.h"

/**
 * pcharop - function to print char in a stack
 * @head: Head of the list
 * @count: line of the monty file
 * @line: line to free
 * @file: file to free
 */
void pcharop(stack_t **head, unsigned int count, char *line, FILE *file)
{
	if (*head != NULL)
	{
		if ((*head)->n >= 0 && (*head)->n < 128)
			printf("%c\n", (*head)->n);
		else
		{
			free(line);
			fclose(file);
			dprintf(2, "L%d: can't pchar, value out of range\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(line);
		fclose(file);
		dprintf(2, "L%d: can't pchar, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
}
/**
 * modop - function to mod int in a stack
 * @head: Head of the list
 * @count: line of the monty file
 * @line: line to free
 * @file: file to free
 */
void modop(stack_t **head, unsigned int count, char *line, FILE *file)
{
	int addr = 0;
	stack_t *current;
	int n = 0;

	if (*head != NULL)
	{
		current = *head;
		while (current != NULL)
		{
			n++;
			current = current->next; }
		if (n >= 2)
		{
			if ((*head)->n == 0)
			{ dprintf(2, "L%d: division by zero\n", count);
				free_dlistint(*head);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE); }
			else
			{
				addr = (*head)->n;
				delete_dnodeint_at_index(head, 0);
				addr = (*head)->n % addr;
				(*head)->n = addr; }
		}
		else
		{
			free(*head);
			free(line);
			fclose(file);
			dprintf(2, "L%d: can't mod, stack too short\n", count);
			exit(EXIT_FAILURE); }
	}
	else
	{
		free(line);
		fclose(file);
		dprintf(2, "L%d: can't mod, stack too short\n", count);
		exit(EXIT_FAILURE); }
}
