#include "monty.h"
/**
 * f_pall - a function that prints the stack
 * @head: stack head
 * @counter: non used
 * Return: no returns
*/

void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
