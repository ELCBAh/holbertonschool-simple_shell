#include "shell.h"
/**
 * process_input - initializes prototype
 * @line: line passed
 * @argc: pointer to number of arguments
 * @argv: pointer to pointer of string of arguments
 * Description: takes input data and process its content
 * Return: number of arguments or -1 if it fails
 */
int process_input(char *line, int *argc, char ***argv)
{
	char *line_cpy, *token;
	int i = 0;

	line_cpy = malloc(strlen(line) + 1);
	if (!line_cpy)
		return (-1);
	strcpy(line_cpy, line);
	token = strtok(line, " \n");
	while (token)
	{
		(*argc)++;
		token = strtok(NULL, " \n");
	}
	(*argc)++;
	*argv = malloc(sizeof(char *) * (*argc + 1));
	if (!*argv)
		return (-1);
	token = strtok(line_cpy, " \n");
	while (token)
	{
		(*argv)[i] = strdup(token);
		if (!(*argv)[i])
			return (-1);
		i++;
		token = strtok(NULL, " \n");
	}
	(*argv)[i] = NULL;
	free(line_cpy);
	return (i);
}
