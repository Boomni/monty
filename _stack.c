#include "monty.h"

int stack_mode = STACK_MODE;

/**
 * _stack - changes the direction of the linked list, so that it becomes a stack
 *		(i.e., elements are added and removed from the top of the stack)
 *
 * @stack: stack
 * @line_number: line number in file
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	stack_mode = STACK_MODE;
}
#include "monty.h"

/**
 * _queue - change the way elements are added and removed from the list
 *
 * @stack: stack
 * @line_number: line_number in file
 *
 * Return: void
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	stack_mode = QUEUE_MODE;
}
