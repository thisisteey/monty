#include "monty.h"

/**
 * stk_rotl - rotates the stack to the top
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_rotl(stack_t **top, unsigned int count)
{
	stack_t *tmpnode = *top, *currhead;
	(void)count;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	currhead = (*top)->next;
	currhead->prev = NULL;
	while (tmpnode->next)
	{
		tmpnode = tmpnode->next;
	}
	tmpnode->next = *top;
	(*top)->next = NULL;
	(*top)->prev = tmpnode;
	(*top) = currhead;
}

/**
 * stk_rotr - rotates the stack to the bottom
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_rotr(stack_t **top, unsigned int count)
{
	stack_t *cpnode;
	(void)count;

	cpnode = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (cpnode->next)
	{
		cpnode = cpnode->next;
	}
	cpnode->next = *top;
	cpnode->prev->next = NULL;
	cpnode->prev = NULL;
	(*top)->prev = cpnode;
	(*top) = cpnode;
}
