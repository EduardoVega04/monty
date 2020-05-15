#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	new_node->next = *stack;
	*stack = new_node;
}

void pall(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit (EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit (EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

void swap(stack_t **stack, unsigned int line_number)
{
	int i;
	int cont = 0;
	int val_firstNode = 0;
	stack_t *tmp = *stack;

	for (i = 0; i < 2 && tmp != NULL; i++)
	{
		if (i == 0 && tmp->next != NULL)
		{
			val_firstNode = tmp->n;
			tmp->n = tmp->next->n;
		}

		if (i == 1)
			tmp->n = val_firstNode;

		cont++;
		tmp = tmp->next;
	}

	if (cont < 2)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
		exit (EXIT_FAILURE);
	}
}

