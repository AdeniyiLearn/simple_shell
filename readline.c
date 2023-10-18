#include "simple_shell.h"

/**
 * remove_reading_space - removes extra space characters
 * @buffer: double pointer to the location reading characters from
 * @line: pointer to the location writing the cleaned characters
 * Return: void
 */

int remove_reading_space(char **buffer, char *line)
{
	int index, num, count;

	for (index = 0; index < _strlen(*buffer); index++)
		if ((*buffer)[index] != ' ' && (*buffer)[index] != '\0')
			break;

	if ((*buffer)[index] == '\0')
	{
		return (0);
	}
	for (num = 0; (*buffer)[index] != '\0'; num++)
	{
		if ((*buffer)[index] == ' ')
		{
			if ((*buffer)[index + 1] == ' ')
			{
				line[num] = (*buffer)[index];
				for (count = index + 1; (*buffer)[count] != '\0'; count++)
				{
					if ((*buffer)[count] != ' ')
					{
						num++;
						break;
					}
				}
				index = count;
				line[num] = (*buffer)[index];
			}
		}
		line[num] = (*buffer)[index];
		index++;
	}
	line[num] = '\0';
	return (_strlen(line));
}

/**
 * _readline - reads input from the command line.
 * @line: pointer to an array to hold the input line.
 * Return: number of bytes read or just -1 on failure.
 */

int _readline(char *line)
{
	char character = '\0', *buffer;
	int index = 0;
	int char_read, size = 10;

	buffer = (char *)malloc(sizeof(char) * size);
	_memset(buffer, 0, sizeof(char) * size);
	while (character != EOF && character != 10)
	{
		char_read = read(STDIN_FILENO, &character, 1);

		if (char_read == 0 || char_read < 0)
		{
			free(buffer);
			return (-1);
		}

		if (index >= size)
		{
			size += 5;
			buffer = realloc(buffer, size);
			_memset(buffer + index, 0, sizeof(char) * 5);
		}

		if (character != 10)
		{
			buffer[index] = character;
			index++;
		}
		else
		{
			break;
		}
	}
	buffer[index] = '\0';
	index = 0;
	index = remove_reading_space(&buffer, line);
	free(buffer);
	return (index);
}

/**
 * _memset - used to set a block of memory with a particular value.
 * @arrow: a pointer to the block of memory to be set.
 * @set_value: is the value to which each byte in the block will be set.
 * @num_set: is the number of bytes to be set.
 * Return: a pointer to the block pf memory set.
 */

char *_memset(char *arrow, char set_value, unsigned int num_set)
{
	unsigned int index = 0;

	while (index < num_set)
	{
		*(arrow + index) = set_value;
		index++;
	}

	return (arrow);
}
