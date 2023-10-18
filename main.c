#include "simple_shell.h"

/**
 * main - The shell's entry point and waits for user input.
 * @ac: argument count(unused)
 * @av: array of commandline arguments.
 * Return: exit with success signal unless interrupted.
 */
int main(int ac __attribute__((unused)), char **av)
{
	if (isatty(0))
	{
		do {
			signal(SIGINT, _ctrlC);
			prompt();
			execution_call(av[0]);
		} while (1);
	}
	else
	{
		do {
			execution_call(av[0]);
		} while (1);
	}
	exit(errno);
}
