#include "monty.h"

/**
 * push - pushes an element to the stack.
 *
 * @stack: stack
 * @line_number: line number in file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;
	char *str;

	str = strtok(NULL, " \n\t");
	if (str == NULL || !isdigit(str))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(str);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * is_integer - checks whether a given string represents a valid integer or not
 *
 * @str: string to check
 *
 * Return: 1 if the string represents a valid integer, 0 otherwise
 */
int is_integer(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return 0;
		}
		str++;
	}
	return 1;
}

