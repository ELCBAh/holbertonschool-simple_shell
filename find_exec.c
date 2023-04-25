#include "shell.h"
/**
 * find_exec - initializes prottype
 * @command: command being passed through input
 * Description: takes an input command and looks in path for actual function
 * Return: A duplicate of the PATH previously divided in parts
 */
char *find_exec(char *command)
{
	char *path, *path_cpy, *dir;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		else
			return (NULL);
	}
	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_cpy = strdup(path);
	if (!path_cpy)
		return (NULL);
	dir = strtok(path_cpy, ":");
	while (dir)
	{
		char exec_path[PATH_MAX];

		snprintf(exec_path, sizeof(exec_path), "%s/%s", dir, command);
		if (access(exec_path, X_OK) == 0)
		{
			free(path_cpy);
			return (strdup(exec_path));
		}
		dir = strtok(NULL, ":");
	}
	free(path_cpy);
	return (NULL);
}
