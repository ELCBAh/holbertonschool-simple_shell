#include "shell.h"
/***/
int process_input(char *line, int *argc, char ***argv)
{
	char *line_cpy, *token;
	int i;

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
	strcpy(line_cpy, line);
	token = strtok(line_cpy, " \n");
	for (i = 0; i < *argc - 1 && token != NULL; i++)
	{
		(*argv)[i] = strdup(token);
		if (!(*argv)[i])
			return (-1);
		token = strtok(NULL, " \n");
	}
	(*argv)[*argc - 1] = NULL;
	free(line_cpy);
	return (0);
}
