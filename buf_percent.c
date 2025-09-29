#include "main.h"

/**
 * buf_percent - handles the %% specifier (buffered)
 * @buffer: local buffer to store output
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written (1)
 */
int buf_percent(char *buffer, int *buf_index)
{
	buffer[*buf_index] = '%';
	(*buf_index)++;
	if (*buf_index == 1024)
	{
		write(1, buffer, *buf_index);
		*buf_index = 0;
	}
	return (1);
}
