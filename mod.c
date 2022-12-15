#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the stack
 * by the top element of the stack.
 *
 * @stack: stack
 * @line_number: line_number in file
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int top;
	int second_top;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	second_top = (*stack)->next->n;
	if (top == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = second_top % top;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
