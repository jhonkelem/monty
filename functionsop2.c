#include "monty.h"

/**
 * divop - function to div int in a stack
 * @head: Head of the list
 * @count: line of the monty file
 * @line: line to free
 * @file: file to free
 */
void divop(stack_t **head, unsigned int count, char *line, FILE *file)
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
				addr = (*head)->n / addr;
				(*head)->n = addr; }
		}
		else
		{
			free(*head);
			free(line);
			fclose(file);
			dprintf(2, "L%d: can't div, stack too short\n", count);
			exit(EXIT_FAILURE); }
	}
	else
	{
		free(line);
		fclose(file);
		dprintf(2, "L%d: can't div, stack too short\n", count);
		exit(EXIT_FAILURE); }
}
/**
 * addop - function to push int in a stack
 * @head: Head of the list
 * @count: line of the monty file
 * @line: line to free
 * @file: file to free
 */
void addop(stack_t **head, unsigned int count, char *line, FILE *file)
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
			current = current->next;
		}

		if (n >= 2)
		{
			addr = (*head)->n;
			delete_dnodeint_at_index(head, 0);
			addr = addr + (*head)->n;
			(*head)->n = addr;
		}
		else
		{
			free(*head);
			free(line);
			fclose(file);
			dprintf(2, "L%d: can't add, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(line);
		fclose(file);
		dprintf(2, "L%d: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
}
/**
 * swapop - function to push int in a stack
 * @head: Head of the list
 * @count: line of the monty file
 * @line: line to free
 * @file: file to free
 */
void swapop(stack_t **head, unsigned int count, char *line, FILE *file)
{
	stack_t *current, *second;
	int n = 0;

	if (*head != NULL)
	{
		current = *head;
		while (current != NULL)
		{
			n++;
			current = current->next;
		}

		if (n >= 2)
		{
			second = *head;
			*head = (*head)->next;
			second->next = (*head)->next;
			(*head)->prev = NULL;
			second->prev = *head;
			(*head)->next = second;
		}
		else
		{
			free(*head);
			free(line);
			fclose(file);
			dprintf(2, "L%d: can't swap, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(line);
		fclose(file);
		dprintf(2, "L%d: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

}
/**
 * mulop - function to mul int in a stack
 * @head: Head of the list
 * @count: line of the monty file
 * @line: line to free
 * @file: file to free
 */
void mulop(stack_t **head, unsigned int count, char *line, FILE *file)
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
			current = current->next;
		}

		if (n >= 2)
		{
			addr = (*head)->n;
			delete_dnodeint_at_index(head, 0);
			addr = (*head)->n * addr;
			(*head)->n = addr;
		}
		else
		{
			free(*head);
			free(line);
			fclose(file);
			dprintf(2, "L%d: can't mul, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(line);
		fclose(file);
		dprintf(2, "L%d: can't mul, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
}
