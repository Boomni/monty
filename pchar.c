#include "monty.h"
/* The ascii value must be between these values to be valid */
#define ASCII_MIN 0
#define ASCII_MAX 127
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
	/* Get the ascii value from the top of the stack */
	int ascii = (*stack)->n;

	/* Check if the stack is empty */
	if (!stack)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}


	/* Check if the ascii value is within the valid range */
	if (ascii < ASCII_MIN || ascii > ASCII_MAX)
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the character with the given ascii value */
	printf("%c\n", (char) ascii);
}
