#include "shell.h"
/***/
void free_all(char *line, char **argv, int argc)
{
	int i;

	free(line);
	for (i = 0; i < argc - 1; i++)
		free(argv[i]);
	free(argv);
}
