#include "monty.h"

/**
 * rotr - sdd
 *
 * @stack: stack
 * @line_number: line number in file
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	copy = *stack;
	(void) line_number;

	if (copy == NULL || copy->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack
		;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
