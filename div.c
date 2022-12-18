#include "monty.h"

/**
 * division - divides second top element of stack by top element of stack.
 * stores the result in the second element.
 * top element is removed after the operation.
 *
 * @stack: pointer to a pointer to the top element of the stack
 * @line_number: line number in file
 *
 * Return: void
 */
void division(stack_t **stack, unsigned int line_number)
{
	int result;

	/* Check if the stack has fewer than two elements */
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Check if the top element is 0 */
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Divide second element by the top element and store the result */
	result = ((*stack)->next->n) / ((*stack)->n);
	/*Remove the top node*/
	pop(stack, line_number);
	/* Store result in the second element */
	(*stack)->n = result;
}
