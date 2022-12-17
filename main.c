#include "monty.h"

/**
 * main - entry point
 *
 * @argv: command line argument
 * @argc: argument count
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp;
	stack_t *stack = NULL;
	instruction_t arg[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &division},
		{"mul", &mul},
		{"mod", &mod},
		{"pchar", &pchar},
		{"pstr", &pstr},
		{"rotl", &rotl},
		{"rotr", &rotr},
		{NULL, NULL}
	};
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parser(fp, arg, &stack, line_number);
	return (0);
}
/**
 * free_stack - frees the stack
 *
 * @stack: stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	if (stack == NULL)
		return;
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
/**
 * parser - reads the command line file passed
 *
 * @fp: file passed
 * @arg: opcode passed
 * @stack: stack
 * @line_number: line number in the file
 *
 * Return: void
 */
void parser(FILE *fp, instruction_t arg[], stack_t **stack, int line_number)
{
	char *line = NULL;
	size_t n = 0;
	char *opcode;
	int i = 0;
	char *original_line;

	while (getline(&line, &n, fp) != -1)
	{
		original_line = strdup(line);
		opcode = strtok(original_line, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
		{
			free(original_line);
			continue;
		}
		opcode = trim_spaces(opcode);
		i = 0;
		while (arg[i].opcode && opcode)
		{
			if (strcasecmp(arg[i].opcode, opcode) == 0)
			{
				arg[i].f(stack, line_number);
				break;
			}
			i++;
		}
		if (arg[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_stack(*stack);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		line_number++;
		free(original_line);
	}
	free(line);
	free_stack(*stack);
	fclose(fp);
}
char *trim_spaces(char *str)
{
	char *end;

	/* Trim leading spaces */
	while (isspace(*str))
		str++;

	/* Trim trailing spaces */
	end = str + strlen(str) - 1;
	while (end > str && isspace(*end))
		end--;

	/* Write new null terminator */
	*(end + 1) = '\0';

	return (str);
}

