#include "monty.h"

/**
 * add -  adds the top two elements of the stack.
 *
 * @stack: pointer to a pointer to the top element of the stack
 * @line_number: line number in test file
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	/* Check if the stack has fewer than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Add top two elements of the stack and store the result */
	result = (*stack)->n + (*stack)->next->n;

	/* Set 'tmp' to the top element of the stack */
	tmp = *stack;
	/* Set the top element of the stack to the second element */
	*stack = (*stack)->next;
	free(tmp);
	/* Store the result of the addition in the second element */
	(*stack)->n = result;
}
