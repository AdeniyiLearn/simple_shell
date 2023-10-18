#include "simple_shell.h"

/**
 * free_node - releases memory location held by the argument vector node.
 * @node_ptr: Double pointer to a node to free.
 *
 * Return: void;
 *
 */

void free_node(create_cmd **node_ptr)
{
	size_t ind = 1;

	free((*node_ptr)->command);

	while ((*node_ptr)->argument[ind] != NULL)
	{
		free((*node_ptr)->argument[ind]);
		ind++;
	}
	free((*node_ptr)->argument);

	free(*node_ptr);
	*node_ptr = NULL;
}
