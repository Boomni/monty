#include "monty.h"

/**
 * pstr -i
 *
 * @stack: stack
 * @line_number: line number in file
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	(void) line_number;

	if (stack == NULL)
	{
		printf("\n");
		return;
	}

	curr = *stack;
	while (curr != NULL && curr->n != 0 && curr->n >= 0 && curr->n <= 127)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}
