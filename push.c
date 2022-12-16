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
	/* Check if the argument is NULL */
	if (str == NULL || !is_integer(str))
	{
		fprintf(stderr, "L%u usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Convert the string to an integer */
	value = atoi(str);
	/* Allocate memory for a new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	/* Update the previous node's next pointer */
	if (*stack != NULL)
		(*stack)->prev = new_node;
	/* Update the stack pointer */
	*stack = new_node;
}
/**
 * is_integer - checks
 *
 * @str: arg
 *
 * Return: 1 or 0
 */
int is_integer(char *str)
{
	/* Check if the string is empty */
	if (*str == '\0')
		return (0);
	/* Check if the string starts with a '-' or '+' character */
	if (*str == '-' || *str == '+')
		str++;
	/* Check if the string contains any non-digit characters */
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
