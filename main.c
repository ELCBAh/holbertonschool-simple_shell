#include "shell.h"
/**
 * main - initializes function
 * @argc: argument count
 * @argv: pointer to string containing arguments
 * Description: organizes data and sends info to necessary functions
 * Return: -1 if fails, 0 otherwise
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len_line = 0;
	ssize_t n_read;

	argc = 0;
	while (1)
	{
		printf("$ ");
		n_read = read_input(&line, &len_line);
		if (n_read < 0)
			return (-1);
		if (process_input(line, &argc, &argv) < 0)
			return (-1);
		exec_function(argv);
		free_all(line, argv, argc);
		argv = NULL;
		len_line = 0;
	}
	return (0);
}
