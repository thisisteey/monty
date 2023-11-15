#include "monty.h"

/**
 * stk_add - adds the values of the top two elements of the stack
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_add(stack_t **top, unsigned int count)
{
	stack_t *currhead;
	int lent = 0;
	int sum;

	currhead = *top;
	while (currhead != NULL)
	{
		currhead = currhead->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	currhead = *top;
	sum = currhead->n + currhead->next->n;
	currhead->next->n = sum;
	*top = currhead->next;
	free(currhead);
}

/**
 * stk_sub - subtracts the top element from the second element of the stack
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_sub(stack_t **top, unsigned int count)
{
	stack_t *currhead;
	int diff, nd;

	currhead = *top;
	for (nd = 0 ; currhead != NULL ; nd++)
		currhead = currhead->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	currhead = *top;
	diff = currhead->next->n - currhead->n;
	currhead->next->n = diff;
	*top = currhead->next;
	free(currhead);
}

/**
 * stk_mul - multiplies the top two elements of the stack
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_mul(stack_t **top, unsigned int count)
{
	stack_t *currhead;
	int lent = 0;
	int prod;

	currhead = *top;
	while (currhead != NULL)
	{
		currhead = currhead->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	currhead = *top;
	prod = currhead->next->n * currhead->n;
	currhead->next->n = prod;
	*top = currhead->next;
	free(currhead);
}

/**
 * stk_div - divides the second element by the top element of the stack
 * @top: double pointer to the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_div(stack_t **top, unsigned int count)
{
	stack_t *currhead;
	int lent = 0;
	int quot;

	currhead = *top;
	while (currhead != NULL)
	{
		currhead = currhead->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	currhead = *top;
	if (currhead->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	quot = currhead->next->n / currhead->n;
	currhead->next->n = quot;
	*top = currhead->next;
	free(currhead);
}

/**
 * stk_mod - computes the remainder of the division of the second
 * top element of the stack by the top element of the stack
 * @top: double pointer to the top of the head of the stack
 * @count: line number in the monty file
 * Return: void
 */
void stk_mod(stack_t **top, unsigned int count)
{
	stack_t *currhead;
	int lent = 0;
	int rmndr;

	currhead = *top;
	while (currhead != NULL)
	{
		currhead = currhead->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	currhead = *top;
	if (currhead->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(progctx.fileptr);
		free(progctx.lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	rmndr = currhead->next->n % currhead->n;
	currhead->next->n = rmndr;
	*top = currhead->next;
	free(currhead);
}
