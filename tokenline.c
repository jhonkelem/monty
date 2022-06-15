#include "monty.h"

/**
 * tokenizeline - function to tokenize line
 * @line: line to tokenize
 * Return: array with tokens
 */
char **tokenizeline(char *line)
{
	char *strt = NULL, **toks1 = _calloc(1, 1024), *delimi = " \t\r\n\a";
	int count1 = 0;

	if (toks1 == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strt = strtok(line, delimi);
	for (count1 = 0; strt != NULL; count1++)
	{
		toks1[count1] = strt;
		strt = strtok(NULL, delimi);
	}
	if (toks1[0] == NULL)
		toks1[0] = "\n";
	return (toks1);
}
