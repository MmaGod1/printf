#include "main.h"

/**
 * buf_string - handles the %s specifier (buffered)
 * @s: string to print
 * @buffer: local buffer to store output
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_string(char *str, char *buffer, int *buf_index, format_flags flags)
{
	int len, count = 0, pad, i;

	if (str == NULL)
		str = "(null)";

	len = strlen(str);

	/* apply precision: cut string if needed */
	if (flags.precision >= 0 && flags.precision < len)
		len = flags.precision;

	pad = (flags.width > len) ? flags.width - len : 0;

	if (!flags.minus)
		while (pad--)
			count += buf_add(buffer, buf_index, ' ');

	for (i = 0; i < len; i++)
		count += buf_add(buffer, buf_index, str[i]);

	if (flags.minus)
		while (pad--)
			count += buf_add(buffer, buf_index, ' ');

	return (count);
}
