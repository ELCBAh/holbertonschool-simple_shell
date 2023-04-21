#include "shell.h"
/***/
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len_line = 0;
	ssize_t n_read;

	while (1)
	{
		printf("$ ");
		n_read = read_input(&line, &len_line);
		if (n_read < 0)
			return (-1);
		argc = 0;
		if (process_input(line, &argc, &argv) < 0)
			return (-1);
		exec_function(argv);
		free_all(line, argv, argc);
		len_line = 0;
	}
	return (0);
}
