#include "shell.h"

/**
 * tokenize - splits a string and returns an array of each word of the string.
 * @line: string to tokenize
 *
 * Return: Pointer to pointer to an array of words
 */
char **tokenize(char *line)
{
	char *line_cpy = NULL, *token = NULL, *delim = " \t\n";
	char **args = NULL;
	int n_args = 0, i = 0;

	line_cpy = strdup(line);
	if (!line_cpy)
		return (NULL);
	token = strtok(line_cpy, delim);
	while (token)
	{
		n_args++;
		token = strtok(NULL, delim);
	}
	free(line_cpy);
	n_args++;
	args = malloc(sizeof(char *) * n_args);
	if (!args)
		return (NULL);
	token = strtok(line, delim);
	for (i = 0; i < n_args - 1 && token != NULL; i++)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			while (--i >= 0)
				free(args[i]);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	return (args);
}
