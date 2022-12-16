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
	int count;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	if (count < 2)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	result = temp->n * temp->next->n;
	temp->next->n = result;
	(*stack) = temp->next;
	free(temp);
}
