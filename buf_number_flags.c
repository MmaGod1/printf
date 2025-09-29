#include "main.h"

/**
 * buf_number_flags - Formats and buffers a signed integer with flags.
 *
 * Description:
 *   Handles formatting of signed decimal integers (`d`, `i` specifiers).
 *   Supports:
 *     - '+' flag: forces a '+' sign before positive numbers.
 *     - ' ' flag: prefixes a leading space before positive numbers if '+' is not set.
 *     - field width: pads output with spaces to the given minimum width.
 *     - '-' flag: left-aligns the output within the field width.
 *     - length modifiers: caller already casts to short/long.
 *
 * @num:       The signed integer to format (already casted by caller).
 * @buffer:    Output buffer used by _printf.
 * @buf_index: Current write position in the buffer (updated by function).
 * @flags:     Active formatting flags and width information.
 *
 * Return: Number of characters written to the buffer.
 */
int buf_number_flags(long num, char *buffer, int *buf_index, format_flags flags)
{
	char temp[64];
	int len, count = 0, pad, i, t_index = 0;

	if (num >= 0)
	{
		if (flags.plus)
			temp[t_index++] = '+';
		else if (flags.space)
			temp[t_index++] = ' ';
	}

	sprintf(temp + t_index, "%ld", num);
	len = strlen(temp);

	pad = (flags.width > len) ? flags.width - len : 0;

	if (!flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, ' ');

	for (i = 0; i < len; i++)
		count += buf_add(buffer, buf_index, temp[i]);

	if (flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, ' ');

	return (count);
}
