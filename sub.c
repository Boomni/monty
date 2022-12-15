#include "monty.h"

/**
 * sub - subtracts top element of stack
 *
 * @stack: stack given
 * @line_number: line number in test file
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	result = second->n - first->n;

	second->n = result;

	*stack = second;
	free(first);
}
