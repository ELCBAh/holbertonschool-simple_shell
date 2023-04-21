#include "shell.h"
/***/
char *find_exec(char *command)
{
	char *path, *path_cpy, *dir;

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
