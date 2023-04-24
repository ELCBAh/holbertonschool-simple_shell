#include "shell.h"
/**
 * free_all - initializes prototype
 * @line: line passed
 * @argv: argument string pointer
 * @argc: argument count
 * Description: frees every allocated memmory
 */
void free_all(char *line, char **argv, int argc)
{
	int i;

	free(line);
	if (!argv)
		return;
	for (i = 0; i < argc; i++)
		free(argv[i]);
	free(argv);
}
