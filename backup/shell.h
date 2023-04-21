#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t read_input(char **line, size_t *len_line);
int process_input(char *line, int *argc, char ***argv);
void exec_function(char **argv);
void free_all(char *line, char **argv, int argc);
char *find_exec(char *command);

#endif
