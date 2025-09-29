#include "main.h"

/**
 * buf_pointer_flags - handles pointer with optional flags
 */
int buf_pointer_flags(void *ptr, char *buffer,
		int *buf_index, format_flags flags)
{
	(void)flags; /* no flags defined for %p */
	return buf_pointer(ptr, buffer, buf_index);
}
