#include "monty.h"

/**
 * mod - computes rest of the division of the second top element of the stack
 * by the top element of the stack.
 *
 * @stack: stack
 * @line_number: line_number in file
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_number);/*For top node*/
	(*stack)->n = result;
}
