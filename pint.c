#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pint - display first value at the top of the stack
 * @stack: stack provided by main in start.c
 * @line_count: line count
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_count)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}
