#include "main.h"

/**
 * buf_number_flags - handles integer with flags (+, space)
 */
int buf_number_flags(int num, char *buffer, int *buf_index, format_flags flags)
{
	int count = 0;

	if (num >= 0)
	{
		if (flags.plus)
			count += buf_add(buffer, buf_index, '+');
		else if (flags.space)
			count += buf_add(buffer, buf_index, ' ');
	}

	count += buf_number(num, buffer, buf_index);
	return (count);
}
