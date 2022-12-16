#include "monty.h"

/**
 * add -  adds the top two elements of the stack.
 *
 * @stack: stack given
 * @line_number: line number in test file
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	(*stack)->n = result;
}
