#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mod -  finds remainder from division
 * @stack: main stack
 * @line_count: line count
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_count);/*For top node*/
	(*stack)->n = result;
}
