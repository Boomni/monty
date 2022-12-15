#include "monty.h"

/**
 * pop - removes the top element of the stack
 *
 * @stack: stack given
 * @line_number: line number in test file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *prev;

	if (stack == NULL || *stack ==NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
        }

        prev = (*stack)->prev;
        free(*stack);
        (*stack) = prev;
	
}
