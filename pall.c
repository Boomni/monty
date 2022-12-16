#include "monty.h"

/**
 * pall - opcode pall prints all the values starting from the top of the stack.
 *
 * @stack: stack given
 * @line_number: line number in test file
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	if (*stack == NULL)
		return;
	while (current != NULL)
	{
		 printf("%d\n", current->n);
		 current = current->next;
	}
}
