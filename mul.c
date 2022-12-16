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
	stack_t *temp;

	if (stack == NULL || (*stack)->prev == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->prev->n = result;
	temp = (*stack);
	(*stack) = (*stack)->prev;
	free(temp);
}
