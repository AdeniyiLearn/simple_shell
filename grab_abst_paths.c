#include "simple_shell.h"

/**
 * _cmd_abs_path - generates absolute path for commands & test if
 * the file path is executable.
 * @cmdname: ptr to the cmd to create absolute path for.
 *
 * Return: executable absolute path.
*/

char *_cmd_abs_path(char *cmdname)
{
	char *pathname, *path, *dup_path, *path_ptr;
	int len;

	if (cmdname == NULL)
		return (NULL);
	if (access(cmdname, X_OK) == 0)
		return (cmdname);
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	dup_path = _strdup(path);
	path_ptr = break_input_line(dup_path, ":");

	while (path_ptr != NULL)
	{
		len = _strlen(path_ptr) + _strlen(cmdname) + 2;
		pathname = (char *)malloc(sizeof(char) * len);
		if (pathname == NULL)
		{
			free(dup_path);
			return (NULL);
		}
		_strcpy(pathname, path_ptr);
		_strcat(pathname, "/");
		_strcat(pathname, cmdname);
		_strcat(pathname, "\0");
		if (access(pathname, X_OK) == 0)
		{
			free(dup_path);
			return (pathname);
		}
		free(pathname);
		pathname = NULL;
		path_ptr = break_input_line(NULL, ":");
	}

	free(dup_path);
	return (NULL);
}
