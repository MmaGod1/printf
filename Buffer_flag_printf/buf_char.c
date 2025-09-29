#include "main.h"

/**
 * buf_char - handles the %c specifier (buffered)
 * @args: list of arguments
 * @buffer: local buffer to store output
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written (1)
 */
int buf_char(va_list args, char *buffer, int *buf_index)
{
	char c = va_arg(args, int);

	buffer[*buf_index] = c;
	(*buf_index)++;
	if (*buf_index == 1024)
	{
		write(1, buffer, *buf_index);
		*buf_index = 0;
	}
	return (1);
}
