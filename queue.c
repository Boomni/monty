#include "monty.h"

int stack_mode = STACK_MODE;

/**
 * _queue - change the way elements are added and removed from the list
 *
 * @stack: stack
 * @line_number: line number in file
 *
 * Return: void
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	stack_mode = QUEUE_MODE;

	(void) stack;
	(void) line_number;
}
