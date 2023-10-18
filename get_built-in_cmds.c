#include "simple_shell.h"

/**
 * func_ptr - checks for any funtion that matches str.
 * @str: input string to search for.
 *
 * Return: pointer to a function that takes string
 * argv as input and returns void
 *
*/

void (*func_ptr(char *str))(char *)
{
	int ind = 0;

	built_in cmd[] = {
		{"env", env},
		{NULL, NULL}
	};

	while (cmd[ind].cmdname != NULL)
	{
		if (_strcmp(cmd[ind].cmdname, str) == 0)
		{
			return (cmd[ind].function);
		}
		ind++;
	}

	return (NULL);
}
