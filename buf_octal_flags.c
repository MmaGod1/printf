#include "main.h"
/**
 * buf_octal_flags - Formats and buffers an unsigned integer in octal.
 *
 * Supports:
 *   - '#' flag: prefix non-zero numbers with '0'.
 *   - field width (spaces or zeros).
 *   - '-' flag: left-align within field width.
 *   - '0' flag: zero-padding (ignored if '-' is set).
 */
int buf_octal_flags(unsigned long num, char *buffer,
		int *buf_index, format_flags flags)
{
	char temp[64];
	int len, count = 0, pad, i, digits_len;
	char pad_char = ' ';
	int prefix = (flags.hash && num != 0);

	sprintf(temp, "%lo", num);
	len = strlen(temp);
	digits_len = len;

	/* Precision */
	if (flags.precision == 0 && num == 0)
	{
		temp[0] = '\0';
		len = digits_len = 0;
	}
	else if (flags.precision > digits_len)
	{
		int diff = flags.precision - digits_len;
		memmove(temp + diff, temp, digits_len + 1);
		memset(temp, '0', diff);
		len += diff;
	}

	if (prefix)
		len += 1;

	pad = (flags.width > len) ? flags.width - len : 0;
	if (flags.zero && !flags.minus && flags.precision < 0)
		pad_char = '0';

	if (!flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, pad_char);

	if (prefix)
		count += buf_add(buffer, buf_index, '0');

	for (i = 0; i < len; i++)
		count += buf_add(buffer, buf_index, temp[i]);

	if (flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, ' ');

	return (count);
}
