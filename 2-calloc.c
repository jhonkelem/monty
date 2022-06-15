#include "monty.h"
#include <string.h>
#include <stdlib.h>
/**
 *_calloc - Allocates memeory for an array
 * @nmemb: Elements of array
 * @size: Size of array
 * Return: Return pinter to memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *x;
	unsigned int y;

	if (nmemb == 0 || size == 0)
		return (NULL);
	x = malloc(nmemb * size);
	if (x == NULL)
		return (NULL);
	for (y = 0; y < (nmemb * size); y++)
{
	x[y] = 0;
}
	return (x);
}
