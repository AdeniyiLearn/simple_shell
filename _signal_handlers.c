#include "simple_shell.h"

/**
 * _ctrlC - respond to user interrupt signals.
 *
 * @sig: not used
 *
 * Return: void.
*/

void _ctrlC(int sig __attribute__((unused)))
{
	_putchar('\n');
	prompt();
}
