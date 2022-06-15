#include "monty.h"

/**
 * processl - function to tokenize line and search opcode
 * @toks1: tokenized elements
 * @head: first item in Stack
 * @count: line of monty file
 * @line: line for free
 * @file: object file for close
 */
void processl(char **toks1, stack_t **head, unsigned int count,
	      char *line, FILE *file)
{
	int flag = 0, count1 = 0;
	instruction_t opc[] = {
		{"pop", popop}, {"div", divop}, {"pall", pallop}, {"swap", swapop},
		{"sub", subop}, {"pint", pintop}, {"add", addop}, {"mul", mulop},
		{"pchar", pcharop}, {"mod", modop} };

	if (_strcmp(toks1[0], "push") == 0)
	{
		if (toks1[1])
			pushop(head, count, toks1, line, file);
		else
		{
			free(*head);
			free(toks1);
			free(line);
			fclose(file);
			dprintf(2, "L%d: usage: push integer\n", count);
			exit(EXIT_FAILURE); } }
	else
	{
		while (count1 < 10)
		{
			if (_strcmp(toks1[0], opc[count1].opcode) == 0)
			{
				free(toks1);
				opc[count1].f(head, count, line, file);
				count1 = 9;
				flag = 1; }
			count1++; }
		if (flag == 0)
		{
			dprintf(2, "L%d: unknown instruction %s\n", count, toks1[0]);
			free(toks1);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE); }
	}
	/*free(toks1);*/
}
