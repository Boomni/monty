#include "monty.h"

/**
 * mul - multiplies second top element of stack with top element of the stack
 *
 * @stack: stack
 * @line_number: line_number in file
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);/*For top node*/
	(*stack)->n = result;
}
