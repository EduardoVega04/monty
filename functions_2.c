#include "monty.h"

stack_t *head = NULL;

void read_file(FILE *stream)
{
	ssize_t characters_read = 0;
	int lineNumber = 0;
	size_t buff_size = 0;
	char *line = NULL;

	while ((characters_read = getline(&line, &buff_size, stream)) != -1)
	{
		lineNumber++;
		split_line(line, lineNumber);
	}
}

void split_line(char *line, unsigned int line_number)
{
	char *delimiters = " ;,!¡¿?'\"\n\t";
	char **instructions = NULL;
	char *token = NULL;
	int i, largo;

	for (largo = 0; line[largo] != '\0'; largo++)
		;

	instructions = malloc(50);
	for (i = 0; i < 2; i++)
	{
		instructions[i] = malloc(largo);
	}

	token = strtok(line, delimiters);
	instructions[0] = token;

	token = strtok(NULL, delimiters);
	instructions[1] = token;

	if (!instructions[0])
		return;

	execute_opcode(instructions, line_number);
}

void execute_opcode(char **instructions, int line_number)
{
	if (strcmp(instructions[0], "push") == 0)
	{
		push(&head, atoi(instructions[1]));
	}
	else if (strcmp(instructions[0], "pall") == 0)
	{
		pall(&head);
	}
	else if (strcmp(instructions[0], "pint") == 0)
	{
		pint(&head, line_number);
	}
	else if (strcmp(instructions[0], "pop") == 0)
	{
		pop(&head, line_number);
	}
	else if (strcmp(instructions[0], "swap") == 0)
	{
		swap(&head, line_number);
	}
	else if (strcmp(instructions[0], "add") == 0)
	{
		add(&head, line_number);
	}
	else
	{
		fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, instructions[0]);
		exit(EXIT_FAILURE);
	}
}

void add(stack_t **stack, unsigned int line_number)
{
	int suma = 0;
	stack_t *tmp = *stack;

	suma += (*stack)->n;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n += suma;

	free(tmp);
}

void nop()
{
	return;
}

