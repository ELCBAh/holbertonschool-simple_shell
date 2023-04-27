#include "shell.h"

/**
 * exe_cmd - execute a line command
 * @args: command and parameters to execute
 *
 * Return: 0 in success or EXIT_FAILIURE
 */
int exe_cmd(char **args)
{
	char *path_cmd = NULL, **env = environ;
	pid_t pid;
	int status;

	if (strcmp(args[0], "env") == 0)
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return (0);
	}
	path_cmd = get_path(args[0]);
	if (path_cmd == NULL)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork() error");
		free(path_cmd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(path_cmd, args, environ);
		perror(path_cmd);
		free(path_cmd);
		exit(2);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	free(path_cmd);
	return (0);
}
