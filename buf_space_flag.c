#include "main.h"

/**
 * buf_space_flag - handles ' ' flag for signed numbers
 * @n: integer to print
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_space_flag(int n, char *buffer, int *buf_index)
{
	int count = 0;

	if (n >= 0)
	{
		buf_addchar(buffer, buf_index, ' ');
		count++;
	}
	count += buf_number(n, buffer, buf_index);

	return (count);
}
