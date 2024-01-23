#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pchar - displays first int as a char
 * @stack: main stack
 * @line_count: line count
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_count)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}
	if (isprint((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
