#include "main.h"

/**
 * buf_uint_flags - Formats and buffers an unsigned integer with flags.
 *
 * Supports:
 *   - field width (spaces or zeros).
 *   - '-' flag: left-aligns within field width.
 *   - '0' flag: zero-padding (ignored if '-' is set).
 */
int buf_uint_flags(unsigned long num, char *buffer, int *buf_index, format_flags flags)
{
	char temp[64];
	int len, count = 0, pad, i;
	char pad_char = ' ';

	sprintf(temp, "%lu", num);
	len = strlen(temp);

	pad = (flags.width > len) ? flags.width - len : 0;
	if (flags.zero && !flags.minus)
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
