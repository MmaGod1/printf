#include "main.h"

/**
 * buf_octal_flags - handles octal numbers with '#' flag
 */
int buf_octal_flags(unsigned int num, char *buffer,
		int *buf_index, format_flags flags)
{
	int count = 0;

	if (flags.hash && num != 0)
		count += buf_add(buffer, buf_index, '0');

	count += buf_octal(num, buffer, buf_index);
	return (count);
}
