#include "shell.h"
/***/
ssize_t read_input(char **line, size_t *len_line)
{
	return (getline(line, len_line, stdin));
}
