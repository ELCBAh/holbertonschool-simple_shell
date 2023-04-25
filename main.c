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
	int exit_s = 0, i;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		n_read = getline(&line, &len_line, stdin);
		if (n_read < 0)
			break;
		args = tokenize(line);
		if (strcmp(args[0], "exit") == 0)
		{
			exit_s = 1;
			break;
		}
		if (exe_cmd(args) == -1)
			fprintf(stderr, "hsh: %s: command not found.\n", args[0]);
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args), args = NULL;
	}
    free(line);
    if (args)
	{
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
    if (exit_s == 1)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}