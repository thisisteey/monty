#include "monty.h"

/**
 * stk_nop - this function does nothing
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_nop(stack_t **top, unsigned int count)
{
	(void)top;
	(void)count;
}

/**
 * free_stk - frees all nodes in a doubly linked list
 * @top: pointer to the head of the stack
 * Return: void
 */
void free_stk(stack_t *top)
{
	stack_t *currhead;

	currhead = top;
	while (top != NULL)
	{
		currhead = top->next;
		free(top);
		top = currhead;
	}
}
