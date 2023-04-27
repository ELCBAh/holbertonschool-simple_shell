#include "shell.h"

/**
 * _free - free alloc memory
 * @args: pointer to pointer
 *
 */
void _free(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
