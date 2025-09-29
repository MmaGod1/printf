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
	int len, count = 0, pad, i;
	char pad_char = ' ';

	if (flags.hash && num != 0)
		sprintf(temp, uppercase ? "0X%lX" : "0x%lx", num);
	else
		sprintf(temp, uppercase ? "%lX" : "%lx", num);

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
