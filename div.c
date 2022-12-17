#include "monty.h"

/**
 * division - divides second top element of stack by top element of stack.
 *
 * @stack: stack
 * @line_number: line number in file
 *
 * Return: void
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	result = temp->next->n / temp->n;
	temp->next->n = result;

	*stack = temp->next;

	free(temp);
}
