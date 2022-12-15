#include "monty.h"

/**
 * rotr -
 *
 * @stack: stack
 * @line_number: line number in file
 *
 * Return: void
void rotr(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL) {
printf("Usage: rotr\n");
return;
}

stack_t *curr = *stack;
while (curr->next != NULL)
{
curr = curr->next;
}

if (curr->prev != NULL)
{
curr->prev->next = NULL;
curr->prev = NULL;
curr->next = *stack;
(*stack)->prev = curr;
*stack = curr;
}
}
