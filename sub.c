#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _sub -  a function that substracts the value of an initial node from stack
 * @stack: stack provided by main
 * @line_count: count lines
 * Return: void
 */

void _sub(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_count);/*For top node*/
	(*stack)->n = result;
}
