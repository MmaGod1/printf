#include "main.h"

/**
 * buf_unknown - handles unsupported specifiers
 * @spec: the unknown specifier character
 * @buffer: local buffer to store output
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written (2)
 */
int buf_unknown(char spec, char *buffer, int *buf_index)
{
	int count = 0;

	buffer[*buf_index] = '%';
	(*buf_index)++;
	count++;
	if (*buf_index == 1024)
	{
		write(1, buffer, *buf_index);
		*buf_index = 0;
	}

	buffer[*buf_index] = spec;
	(*buf_index)++;
	count++;
	if (*buf_index == 1024)
	{
		write(1, buffer, *buf_index);
		*buf_index = 0;
	}

	return (count);
}
