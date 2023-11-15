#include "monty.h"

/**
 * sq_execute - executes the monty bytecode instructions
 * @lncontent: line content from the monty file
 * @top: double pointer to the head of the stack
 * @count: line counter
 * @fileptr: pointer to the monty file
 * Return: 0 on code success or 1 otherwise
 */
int sq_execute(char *lncontent, stack_t **top,
		unsigned int count, FILE *fileptr)
{
	instruction_t opcds[] = {
				{"push", stk_push}, {"pall", stk_pall},
				{"pint", stk_pint}, {"pop", stk_pop},
				{"swap", stk_swap}, {"add", stk_add},
				{"nop", stk_nop}, {"sub", stk_sub},
				{"div", stk_div}, {"mul", stk_mul},
				{"mod", stk_mod},
				{"pchar", stk_pchar},
				{"pstr", stk_pstr},
				{"rotl", stk_rotl},
				{"rotr", stk_rotr},
				{"queue", qs_queue},
				{"stack", stk_p},
				{NULL, NULL}
	};
	unsigned int x = 0;
	char *curropcd;

	curropcd = strtok(lncontent, " \n\t");
	if (curropcd && curropcd[0] == '#')
		return (0);
	progctx.argval = strtok(NULL, " \n\t");
	while (opcds[x].opcode && curropcd)
	{
		if (strcmp(curropcd, opcds[x].opcode) == 0)
		{
			opcds[x].f(top, count);
			return (0);
		}
		x++;
	}
	if (curropcd && opcds[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, curropcd);
		fclose(fileptr);
		free(lncontent);
		free_stk(*top);
		exit(EXIT_FAILURE);
	}
	return (1);
}
