#include "shell.h"
/***/
void exec_function(char **argv)
{
	pid_t pid;
	int status;
	char *exec_path;

	if (strcmp(argv[0], "exit") == 0)
		exit(0);
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
