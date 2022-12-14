#include "monty.h"

/**
 * pall - opcode pall prints all the values on the stack, starting from the top of the stack.
 *
 * @stack:
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (stack == NULL)
	    return;
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

