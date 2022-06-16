#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, char *line,
		  FILE *file);
} instruction_t;
extern FILE *file;
void processl(char **toks1, stack_t **head, unsigned int count, char *line,
	      FILE *file);
char **tokenizeline(char *line);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
void pushop(stack_t **head, unsigned int count, char **elements, char *line,
	    FILE *file);
void pallop(stack_t **head, unsigned int count, char *line,
	    FILE *file);
void pintop(stack_t **head, unsigned int count, char *line,
	    FILE *file);
void divop(stack_t **head, unsigned int count, char *line,
	   FILE *file);
void subop(stack_t **head, unsigned int count, char *line,
	   FILE *file);
void popop(stack_t **head, unsigned int count, char *line,
	   FILE *file);
void swapop(stack_t **head, unsigned int count, char *line,
	    FILE *file);
void addop(stack_t **head, unsigned int count, char *line,
	   FILE *file);
void mulop(stack_t **head, unsigned int count, char *line,
	   FILE *file);
void modop(stack_t **head, unsigned int count, char *line,
	   FILE *file);
void pcharop(stack_t **head, unsigned int count, char *line,
	     FILE *file);

void free_dlistint(stack_t *head);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
size_t dlistint_len(stack_t *h);
#endif
