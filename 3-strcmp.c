#include "monty.h"

/**
 * _strcmp - function that will compare 2 strings
 * @s1: count s1
 * @s2: count for s2
 * Return: returns the diference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int x;
	int y = 0;
	int rest;

	for (x = 0; s1[x] != '\0'; x++, y++)
	{
		rest = s1[x] - s2[y];

			if (rest != 0)
			{
				break;
			}
	}
	return (rest);

}
