#include "main.h"

/**
 * buf_octal_flags - Formats and buffers an unsigned integer in octal.
 *
 * Description:
 *   Handles formatting of octal integers (`o` specifier).
 *   Supports:
 *     - '#' flag: prefixes non-zero numbers with a leading '0'.
 *     - field width: pads output with spaces to the given minimum width.
 *     - '-' flag: left-aligns the output within the field width.
 *
 * @num:       The unsigned integer to format (already casted by caller).
 * @buffer:    Output buffer used by _printf.
 * @buf_index: Current write position in the buffer (updated by function).
 * @flags:     Active formatting flags and width information.
 *
 * Return: Number of characters written to the buffer.
 */
int buf_octal_flags(unsigned long num, char *buffer,
		int *buf_index, format_flags flags)
{
	char temp[64];
	int len, count = 0, pad, i;

	if (flags.hash && num != 0)
		sprintf(temp, "0%lo", num);
	else
		sprintf(temp, "%lo", num);

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
