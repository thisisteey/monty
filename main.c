#include "monty.h"
progctx_t progctx = {NULL, NULL, NULL, 0};

/**
 * main - entry point of the monty code interpreter
 * @argc: number of arguments
 * @argv: array of arguments, including the monty file location
 * Return: 0 on code success
 */
int main(int argc, char *argv[])
{
	char *lncontent;
	FILE *fileptr;
	size_t linesz = 0;
	ssize_t read_res = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileptr = fopen(argv[1], "r");
	progctx.fileptr = fileptr;
	if (fileptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_res > 0)
	{
		lncontent = NULL;
		read_res = getline(&lncontent, &linesz, fileptr);
		progctx.lncontent = lncontent;
		count++;
		if (read_res > 0)
		{
			sq_execute(lncontent, &stack, count, fileptr);
		}
		free(lncontent);
	}
	free_stk(stack);
	fclose(fileptr);
return (0);
}
