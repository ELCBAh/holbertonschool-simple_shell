#include "shell.h"

/**
 *
 *
 *
 *
 *
 */
int main(int argc, char **argv)
{
	char *line, *line_cpy;
	size_t len_line = 0;
	ssize_t n_read;
	char *token;
	pid_t pid;
	int status, i;

	while (1)
	{
		printf("$ ");
		n_read = getline(&line, &len_line, stdin);
		if (n_read < 0)
			return (-1);
		line_cpy = malloc(sizeof(char) * n_read);
		if (!line_cpy)
			return (-1);
		strcpy(line_cpy, line);
		token = strtok(line, " \n");
		while (token)
		{
			argc++;
			token = strtok(NULL, " \n");
		}
		argc++;
		argv = malloc(sizeof(char *) * argc);
		if (!argv)
			return (-1);
		token = strtok(line_cpy, " \n");
		for (i = 0; i < argc - 1 && token != NULL; i++)
		{
			argv[i] = strdup(token);
			if (!argv[i])
				return (-1);
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;	
		if (strcmp(argv[0], "exit") == 0)
			exit(0);
		pid = fork();
		if (pid == -1)
		{
			perror("fork() error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execv(argv[0], argv);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}	
	}
	free(line);
	free(line_cpy);
	return (0);
}
