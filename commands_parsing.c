#include "simple_shell.h"

/**
 * clean_token - filters and copies the filtered token to tk_copy.
 * if filters a newline and null terminating character from a token.
 * @tk_copy_ptr: pointer to pointer to the filtered token.
 * @token_ptr: pointer to pointer to the token to filter.
 * Return: void/nothing.
*/
void clean_token(char **tk_copy_ptr, char **token_ptr)
{
	int t_len = 0;

	while ((*token_ptr)[t_len] != 10 && (*token_ptr)[t_len] != '\0')
	{
		t_len++;
	}

	*tk_copy_ptr = (char *)malloc(sizeof(char) * (t_len + 1));
	_strncpy(*tk_copy_ptr, *token_ptr, t_len);
	(*tk_copy)[t_len] = '\0';
}

/**
 * process_args - processes the arguments by allocating memory for all
 * command and there args.
 * @cmd: pointer to pointer for a command.
 * @args: thriple pointer to array of arguments.
 * @line_ptr: pointer to input line to craete command and arguments from.
 *
 * @delim: pointer to separator for the line to indivudual worlds.
 * Return: nothing.
*/
void process_args(char **cmd, char ***args, char *line_ptr, char *delim)
{
	char *tok;
	int arg_c;
	char *cpy_token;

	arg_c = 1;

	*args = (char **)malloc(sizeof(char *) * 20);

	if (*args == NULL)
	{
		exit(EXIT_FAILURE);
	}

	tok = break_input_line(line_ptr, delim);

	while (tok != NULL && arg_c < 20)
	{
		if (*cmd == NULL)
		{
			clean_token(&cpy_token, &tok);
			*cmd = cpy_token;
			(*args)[0] = cpy_token;
		}
		else
		{
			clean_token(&cpy_token, &tok);
			(*args)[arg_c++] = cpy_token;
		}

		tok = break_input_line(NULL, delim);
	}

	(*args)[arg_c] = NULL;
}
