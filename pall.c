#include "monty.h"

/**
 * pall - displays the stack
 * @stack: stack provided by main in start.c
 * @line_count: line count
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_count __attribute__((unused)))
{
	print_stack(*stack);
}
