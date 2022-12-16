#include "monty.h"

/**
 * pchar - h
 *
 * @stack: stack
 * @line_number: line number in file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	/* Get the ascii value from the top of the stack */
	stack_t *temp = *stack;

	/* Check if the stack is empty */
	if (!temp)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if the ascii value is within the valid range */
	if (temp->n > 127 || temp->n < 0)
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the character with the given ascii value */
	printf("%c\n", temp->n);
}
