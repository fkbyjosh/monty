#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * swap -  a function that swaps data between top and preceding element
 * @stack: a stack provided by main
 * @line_count: num of lines
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
