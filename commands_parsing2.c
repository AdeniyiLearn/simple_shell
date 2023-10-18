#include "simple_shell.h"

/**
 * parse_cmd - breaks input line into individual strings.
 * and creates a node.
 * @head: pointer to the head node.
 * @line_ptr: single pointer to the input line.
 * @delim: pointer to the delimiter
 *
 * Return: The node created each time.
*/

create_cmd *parse_cmd(create_cmd **head, char *line_ptr, char *delim)
{
	create_cmd *new_node = NULL;
	int index = 1;

	if (*line_ptr == '\0' || line_ptr == NULL)
		return (NULL);

	new_node = (create_cmd *)malloc(sizeof(create_cmd));

	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->command = NULL;
	new_node->argument = NULL;

	if (*head == NULL)
	{
		process_args(&(new_node->command), &(new_node->argument), line_ptr, delim);
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	else
	{
		free((*head)->command);
		(*head)->command = NULL;
		while ((*head)->argument[index] != NULL)
		{
			free((*head)->argument[index]);
			index++;
		}
		free(((*head)->argument));
		(*head)->argument = NULL;
		free(*head);
		*head = NULL;
		process_args(&(new_node->command), &(new_node->argument), line_ptr, delim);
		new_node->next = *head;
		*head = new_node;
	}

	return (new_node);
}
