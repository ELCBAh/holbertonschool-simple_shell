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
	int isatty_check = isatty(STDIN_FILENO);

	argc = 0;
	while (1)
	{
		if (isatty_check)
			printf("$ ");
		n_read = read_input(&line, &len_line);
		if (n_read < 0)
			return (-1);
		if (process_input(line, &argc, &argv) < 0)
			return (-1);
		exec_function(argv);
		argv = NULL;
		free_all(line, argv, argc);
		len_line = 0;
	}
	return (0);
}
