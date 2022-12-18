#include "monty.h"

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
