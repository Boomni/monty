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
	int divisor;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	divisor = (*stack)->n;
	if (divisor == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->n /= divisor;
}
