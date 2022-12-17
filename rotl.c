#include "monty.h"

/**
  * rotl- rotates the stack to the top
  *
  * @stack: stack head
  * @line_number: line_number
  *
  * Return: no return
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *aux;
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	aux = (*stack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}
