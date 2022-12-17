#include "monty.h"

/**
 * pchar - h
 *
 * @stack: stack
 * @line_number: line number in file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (is_ascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * is_ascii - checks for ascii character
 *
 * @c: integer argument to check
 *
 * Return: 0 is false, non-zero if true
 */
int is_ascii(int c)
{
	return ((c & ~0x7F) == 0);
}
