#include "shell.h"

/**
 * main - UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	char **args;
	size_t len_line = 0;
	ssize_t n_read;
	int no_args = 0, e_exit = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		n_read = getline(&line, &len_line, stdin);
		if (n_read < 0)
			break;
		if (only_spaces(line) == 1)
		{
			no_args = 1;
			continue;
		}
		args = tokenize(line);
		if (strcmp(args[0], "exit") == 0)
			break;
		if (exe_cmd(args) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			e_exit = 1;
			break;
		}
		_free(args);
		args = NULL;
	}
	free(line);
	if (no_args == 0)
	{
		if (args)
			_free(args);
	}
	if (e_exit == 1)
		exit(127);
	return (0);
}
