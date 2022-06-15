#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - check the code for Holberton School students.
 * @ac: arguments length
 * @av: arguments array
 * Return: Always 0 if all its ok or Failure if it fails.
 */
int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL, **strt;
	size_t n;
	ssize_t leline;
	stack_t *head;
	unsigned int count = 1;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	while (1)
	{
		leline = getline(&line, &n, file);
		if (leline == EOF)
		{
			free(line);
			free_dlistint(head);
			fclose(file);
			exit(EXIT_SUCCESS);
		}
		strt = tokenizeline(line);
		if (_strcmp(strt[0], "\n") != 0 && _strcmp(strt[0], "nop") &&
			strt[0][0] != '#')
			processl(strt, &head, count, line, file);
		else
			free(strt);
		count++;
	}
	return (0);
}
