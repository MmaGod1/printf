#include "main.h"

/**
 * buf_char - handles the %c specifier (buffered)
 * @args: list of arguments
 * @buffer: local buffer to store output
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written (1)
 */
int buf_char(va_list args, char *buffer, int *buf_index, format_flags flags)
{
	char c = (char)va_arg(args, int);
	int count = 0, pad = (flags.width > 1) ? flags.width - 1 : 0;

	if (!flags.minus)
		while (pad--)
			count += buf_add(buffer, buf_index, ' ');

	count += buf_add(buffer, buf_index, c);

	if (flags.minus)
		while (pad--)
			count += buf_add(buffer, buf_index, ' ');

	return (count);
}
