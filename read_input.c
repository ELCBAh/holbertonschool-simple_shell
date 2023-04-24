#include "shell.h"
/**
 * read_input - initalizes protoype
 * @line: pointer to string containing input line
 * @len_line: line length
 * Description: process input using getline
 * Return: line to standard input
 */
ssize_t read_input(char **line, size_t *len_line)
{
	return (getline(line, len_line, stdin));
}
