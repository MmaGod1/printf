#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * buf_hex_flags - Formats and buffers an unsigned integer in hexadecimal.
 *
 * Description:
 *   Handles formatting of hexadecimal integers (`x` and `X` specifiers).
 *   Supports:
 *     - '#' flag: prefixes non-zero numbers with "0x" (lowercase) or "0X" (uppercase).
 *     - field width: pads output with spaces to the given minimum width.
 *     - '-' flag: left-aligns the output within the field width.
 *   Case of hex digits is controlled by the `uppercase` parameter.
 *
 * @num:        The unsigned integer to format (already casted by caller).
 * @buffer:     Output buffer used by _printf.
 * @buf_index:  Current write position in the buffer (updated by function).
 * @flags:      Active formatting flags and width information.
 * @uppercase:  If non-zero, use uppercase hex digits; otherwise lowercase.
 *
 * Return: Number of characters written to the buffer.
 */
int buf_hex_flags(unsigned long num, char *buffer, int *buf_index,
		format_flags flags, int uppercase)
{
	char temp[64];
	int len, count = 0, pad, i;

	if (flags.hash && num != 0)
		sprintf(temp, uppercase ? "0X%lX" : "0x%lx", num);
	else
		sprintf(temp, uppercase ? "%lX" : "%lx", num);

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
