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
	int i, only_space = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		n_read = getline(&line, &len_line, stdin);
		if (n_read < 0)
			break;
		for (i = 0; line[i] != '\0'; i++)
		{
			if (line[i] != 10 && line[i] != 9 && line[i] != 32)
				only_space = 0;
		}
		if (only_space == 1)
		{
			free(line);
			return (0);
		}
		args = tokenize(line);
		if (strcmp(args[0], "exit") == 0)
			break;
		exe_cmd(args);
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
	return (0);
}
