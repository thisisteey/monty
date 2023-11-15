#include "monty.h"

/**
 * stk_push - adds a new node to the stack
 * @top: double pointer to the head of the stack
 * @num : line number in the monty file
 * Return: void
 */
void stk_push(stack_t **top, unsigned int num)
{
	int x, y = 0;
	int flg = 0;

	if (progctx.argval != NULL)
	{
		if (progctx.argval[0] == '-')
			y++;
		for (; progctx.argval[y] != '\0' ; y++)
		{
			if (progctx.argval[y] > 57 || progctx.argval[y] < 48)
				flg = 1;
		}
		if (flg == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", num);
			fclose(progctx.fileptr);
			free(progctx.lncontent);
			free_stk(*top);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE); }
	x = atoi(progctx.argval);
	if (progctx.flags == 0)
		qs_addnode(top, x);
	else
		qs_addqueue(top, x);
}

/**
 * stk_pop - removes the top element of the stack
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_pop(stack_t **top, unsigned int count)
{
	stack_t *head;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	head = *top;
	*top = head->next;
	free(head);
}

/**
 * stk_swap - swaps the top two elements of the stack
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_swap(stack_t **top, unsigned int count)
{
	stack_t *currhead;
	int lent = 0, tmp;

	currhead = *top;
	while (currhead != NULL)
	{
		currhead = currhead->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	currhead = *top;
	tmp = currhead->n;
	currhead->n = currhead->next->n;
	currhead->next->n = tmp;
}

/**
 * stk_pint - prints the value at the top of the stack
 * @top: double pointer to the head of the stack
 * @pos: line number in the monty file
 * Return: void
 */
void stk_pint(stack_t **top, unsigned int pos)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", pos);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

/**
 * stk_pall - prints all elements in the stack
 * @top: double pointer to the head of the stack
 * @num: line number in the monty file
 * Return: void
 */
void stk_pall(stack_t **top, unsigned int num)
{
	stack_t *currhead;
	(void)num;

	currhead = *top;
	if (currhead == NULL)
		return;
	while (currhead != NULL)
	{
		printf("%d\n", currhead->n);
		currhead = currhead->next;
	}
}
