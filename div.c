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
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_number);/*For top node*/
	(*stack)->n = result;
}
