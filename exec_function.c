#include "shell.h"
/***/
/*
 * Handling env
void print_env(void)
{
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);
}
*/
void exec_function(char **argv)
{
	pid_t pid;
	int status;
	char *exec_path;

	if (strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
	/*
	 * Handling env
	else if (strcmp(argv[0], "env") == 0)
	{
		if (argv[1] == NULL)
		{
			print_env();
		}
		else
		{
			fprintf(stderr, "env: too many arguments\n");
			return;
		}
	}
	*/
	exec_path = find_exec(argv[0]);
	if (!exec_path)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork() error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(exec_path, argv, environ);
		perror(exec_path);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	free(exec_path);
}
