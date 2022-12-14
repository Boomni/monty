#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    char *token = strtok(NULL, " \n\t");
    if (token == NULL || !isdigit(*token))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(token);
    new_node->prev = NULL;
    new_node->next = *stack;
    *stack = new_node;
}

