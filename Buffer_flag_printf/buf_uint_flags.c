#include "main.h"

/**
 * buf_uint_flags - handles unsigned int with flags
 */
int buf_uint_flags(unsigned int num, char *buffer,
		int *buf_index, format_flags flags)
{
	(void)flags; /* no special flags for plain unsigned */
	return buf_uint(num, buffer, buf_index);
}
