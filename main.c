#include "monty.h"

/**
 * main - entry point
 *
 * @argv: command line argument
 * @argc: argument count
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	stack_t *stack = NULL;
	char *line = NULL;
	size_t n = 0;
	char *opcode;
	int i = 0;
	unsigned int line_number =0;
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, fp) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
		{
			continue;
		}
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(instructions[i].opcode, opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
			i++;
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
free(line);
free_stack(stack);
fclose(fp);
return 0;
}
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

