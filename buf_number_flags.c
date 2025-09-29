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
	char pad_char = ' ';
	int digits_start, digits_len;

	/* Handle sign for positive numbers */
	if (num >= 0)
	{
		if (flags.plus)
			temp[t_index++] = '+';
		else if (flags.space)
			temp[t_index++] = ' ';
	}

	/* Convert number to string */
	sprintf(temp + t_index, "%ld", num);
	len = strlen(temp);

	/* Find where digits actually start (skip sign if present) */
	digits_start = (temp[0] == '+' || temp[0] == '-' || temp[0] == ' ') ? 1 : 0;
	digits_len = len - digits_start;

	/* ---- Apply precision ---- */
	if (flags.precision == 0 && num == 0)
	{
		/* Special case: precision=0 with num=0 → no digits */
		temp[digits_start] = '\0';
		len = digits_start;
		digits_len = 0;
	}
	else if (flags.precision > digits_len)
	{
		int diff = flags.precision - digits_len;
		/* Shift digits to the right */
		memmove(temp + digits_start + diff, temp + digits_start, digits_len + 1);
		/* Fill leading zeros */
		memset(temp + digits_start, '0', diff);
		len += diff;
	}

	/* ---- Handle width ---- */
	pad = (flags.width > len) ? flags.width - len : 0;

	/* If precision is specified, '0' flag is ignored */
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
