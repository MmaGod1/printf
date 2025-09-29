#include "main.h"

/**
 * buf_hex_flags - Formats and buffers an unsigned integer in hexadecimal.
 *
 * Supports:
 *   - '#' flag: prefixes non-zero numbers with "0x" or "0X".
 *   - field width (spaces or zeros).
 *   - '-' flag: left-align within field width.
 *   - '0' flag: zero-padding (ignored if '-' is set).
 */
int buf_hex_flags(unsigned long num, char *buffer, int *buf_index,
		format_flags flags, int uppercase)
{
	char temp[64];
	int len, count = 0, pad, i, prefix_len = 0, digits_len;
	char pad_char = ' ';
	char prefix[3] = "";

	if (flags.hash && num != 0)
	{
		prefix[0] = '0';
		prefix[1] = uppercase ? 'X' : 'x';
		prefix[2] = '\0';
		prefix_len = 2;
	}

	sprintf(temp, uppercase ? "%lX" : "%lx", num);
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

	len += prefix_len;

	pad = (flags.width > len) ? flags.width - len : 0;
	if (flags.zero && !flags.minus && flags.precision < 0)
		pad_char = '0';

	if (!flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, pad_char);

	for (i = 0; i < prefix_len; i++)
		count += buf_add(buffer, buf_index, prefix[i]);

	for (i = 0; i < len; i++)
		count += buf_add(buffer, buf_index, temp[i]);

	if (flags.minus)
		for (i = 0; i < pad; i++)
			count += buf_add(buffer, buf_index, ' ');

	return (count);
}
