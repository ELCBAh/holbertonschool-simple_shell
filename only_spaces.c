#include "shell.h"

/**
 * only_spaces - check for a line with only spaces
 * @line: to check
 *
 * Return: 0 or 1
 */
int only_spaces(char *line)
{
	int o_spaces = 1;
	size_t i;

	for (i = 0; i < (strlen(line) - 1); i++)
	{
		if (line[i] != 9 && line[i] != 32)
			o_spaces = 0;
	}
	return (o_spaces);
}
