#include "shell.h"

/**
 * _getenv - gets an environ variable
 * @name: of the environment variable to retrieve
 * 
 * Return: an environ variable or NULL
*/
char *_getenv(char *name)
{
    int i, len = strlen(name);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, len) == 0
        && environ[i][len] == '=')
        {
            return (environ[i] + len + 1);
        }
    }
    return (NULL);
}