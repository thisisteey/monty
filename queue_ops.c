#include "monty.h"

/**
 * qs_addnode - adds a new node to the head of the stack
 * @top: double pointer to the head of the stack
 * @num: new value to the added to the head of the stack
 * Return: void
 */
void qs_addnode(stack_t **top, int num)
{
	stack_t *nnode, *currhead;

	currhead = *top;
	nnode = malloc(sizeof(stack_t));
	if (!nnode)
	{
		printf("Error\n");
		exit(0);
	}
	if (currhead != NULL)
		currhead->prev = nnode;
	nnode->n = num;
	nnode->next = *top;
	nnode->prev = NULL;
	*top = nnode;
}

/**
 * qs_addqueue - adds a new node to the tail of the stack
 * @top: double pointer to the head of the stack
 * @num: new value to be added to the tail of the stack
 * Return: void
 */
void qs_addqueue(stack_t **top, int num)
{
	stack_t *nnode, *currhead;

	currhead = *top;
	nnode = malloc(sizeof(stack_t));
	if (!nnode)
	{
		printf("Error\n");
	}
	nnode->n = num;
	nnode->next = NULL;
	if (currhead != NULL)
	{
		while (currhead->next)
			currhead = currhead->next;
	}
	if (currhead == NULL)
	{
		*top = nnode;
		nnode->prev = NULL;
	}
	else
	{
		currhead->next = nnode;
		nnode->prev = currhead;
	}
}

/**
 * qs_queue - sets the stackmode to a queue using FIFO mode
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void qs_queue(stack_t **top, unsigned int count)
{
	(void)top;
	(void)count;
	progctx.flags = 1;
}
