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
		{"stack", &_stack},
		{"queue", &_queue},
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
