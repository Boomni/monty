#include "monty.h"

/**
 * push - pushes new node to the end of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *temp;
	char *num;

	num = strtok(NULL, " \n\t");
	if (num == NULL || !is_digit(num))
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(num);
	if (stack_mode == STACK_MODE)
	{
		node->prev = NULL;
		node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = node;
		*stack = node;
	}
	else
	{
		node->prev = NULL;
		node->next = NULL;
		if (*stack == NULL)
		{
			node->prev = NULL;
			*stack = node;
		}
		else
		{
			temp = *stack;
			while (temp->next)
				temp = temp->next;
			temp->next = node;
			node->prev = temp;
		}
	}
}
/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
