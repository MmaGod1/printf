#include "main.h"

/**
 * buf_number_flags - Formats and buffers a signed integer with flags.
 *
 * Supports:
 *   - '+' flag: forces a '+' sign before positive numbers.
 *   - ' ' flag: prefixes a space before positive numbers if '+' not set.
 *   - field width: pads output with spaces or zeros.
 *   - '-' flag: left-aligns the output within the field width.
 *   - '0' flag: pads with zeros instead of spaces (ignored if '-' is set).
 */

int buf_number_flags(long num, char *buffer, int *buf_index, format_flags flags)
{
	char temp[128];
	int len, count = 0, pad, i, t_index = 0;
	int digits_start, digits_len;
	char pad_char = ' ';

	/* Handle sign */
	if (num >= 0)
	{
		if (flags.plus)
			temp[t_index++] = '+';
		else if (flags.space)
			temp[t_index++] = ' ';
	}

	sprintf(temp + t_index, "%ld", num);
	len = strlen(temp);

	digits_start = (temp[0] == '+' || temp[0] == '-' || temp[0] == ' ') ? 1 : 0;
	digits_len = len - digits_start;

	/* Apply precision */
	if (flags.precision == 0 && num == 0)
	{
		temp[digits_start] = '\0';
		len = digits_start;
		digits_len = 0;
	}
	else if (flags.precision > digits_len)
	{
		int diff = flags.precision - digits_len;
		memmove(temp + digits_start + diff, temp + digits_start, digits_len + 1);
		memset(temp + digits_start, '0', diff);
		len += diff;
	}

	/* Width */
	pad = (flags.width > len) ? flags.width - len : 0;
	if (flags.zero && !flags.minus && flags.precision < 0)
		pad_char = '0';

	if (!flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, pad_char);

	for (i = 0; i < len; i++)
		count += buf_add(buffer, buf_index, temp[i]);

	if (flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, ' ');

	return (count);
}
