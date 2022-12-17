#include "monty.h"

/**
 * switch_data_format - switches data format between stack and queue
 *
 * @stack: stack
 *
 * Return: void
 */
void switch_data_format(stack_t **stack)
{
	stack_t *front, *back, *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	front = *stack;
	back = (*stack)->next;

	/* switch top of stack to front of queue */
	*stack = back;
	(*stack)->prev = NULL;
	tmp = back;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = front;
	front->prev = tmp;
	front->next = NULL;
}
