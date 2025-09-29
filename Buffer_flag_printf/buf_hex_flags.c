#include "main.h"

/**
 * buf_hex_flags - handles hex with '#' flag
 */
int buf_hex_flags(unsigned int num, char *buffer, int *buf_index,
		format_flags flags, int uppercase)
{
	int count = 0;

	if (flags.hash && num != 0)
	{
		count += buf_add(buffer, buf_index, '0');
		count += buf_add(buffer, buf_index, uppercase ? 'X' : 'x');
	}

	if (uppercase)
		count += buf_HEX(num, buffer, buf_index);
	else
		count += buf_hex(num, buffer, buf_index);

	return (count);
}
