#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(char *name);
char *get_path(char *file);
char **tokenize(char *line);
int exe_cmd(char **args);

#endif