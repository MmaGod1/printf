#include "main.h"

/**
 * buf_string - handles the %s specifier (buffered)
 * @str: string to print
 * @buffer: local buffer to store output
 * @buf_index: pointer to current buffer index
 * @flags: formatting flags (width, precision, minus, etc.)
 *
 * Return: number of characters written
 */
int buf_string(char *str, char *buffer, int *buf_index, format_flags flags)
{
	int i, count = 0, pad;
	int actual_len, print_len;

	if (str == NULL)
		str = "(null)";

	actual_len = strlen(str);

	/* number of characters to print = min(precision, actual_len) */
	if (flags.precision >= 0 && flags.precision < actual_len)
		print_len = flags.precision;
	else
		print_len = actual_len;

	/* Calculate padding */
	pad = (flags.width > print_len) ? flags.width - print_len : 0;

	/* If not left-justified, pad first */
	if (!flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, ' ');

	/* Add the string (up to print_len characters) */
	for (i = 0; i < print_len; i++)
		count += buf_add(buffer, buf_index, str[i]);

	/* If left-justified, pad after */
	if (flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, ' ');

	return count;
}
