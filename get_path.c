#include "shell.h"

/**
 * get_path - looks for files in the current PATH
 * @file: file
 *
 * Return: the file path if found, or NULL
 */
char *get_path(char *file)
{
	char *path_env = NULL;
	char *path = NULL, *file_path = NULL;
	struct stat buf;

	if (file[0] == '/')
	{
		if (stat(file, &buf) == 0)
			return (strdup(file));
		return (NULL);
	}
	else
	{
		path_env = strdup(_getenv("PATH"));
		if (path_env == NULL)
		{
			return (NULL);
		}
		path = strtok(path_env, ":");
		while (path)
		{
			file_path = malloc(sizeof(char) * (strlen(path) + strlen(file) + 2));
			sprintf(file_path, "%s/%s", path, file);
			if (stat(file_path, &buf) == 0)
			{
				free(path_env);
				return (file_path);
			}
			path = strtok(NULL, ":");
			free(file_path);
		}
	}
	free(path_env);
	return (NULL);
}
