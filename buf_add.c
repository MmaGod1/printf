#include "main.h"

/**
 * buf_addchar - adds a single character to buffer
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 * @c: character to add
 */
void buf_addchar(char *buffer, int *buf_index, char c)
{
	buffer[*buf_index] = c;
	(*buf_index)++;

	if (*buf_index == 1024 || c == '\n')
	{
		write(1, buffer, *buf_index);
		*buf_index = 0;
	}
}
