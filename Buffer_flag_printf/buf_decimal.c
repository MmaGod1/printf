#include "main.h"

/**
 * buf_uint - handles %u specifier (buffered)
 * @n: unsigned int to print
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_uint(unsigned int n, char *buffer, int *buf_index)
{
	int count = 0;

	if (n / 10)
		count += buf_uint(n / 10, buffer, buf_index);

	buf_addchar(buffer, buf_index, (n % 10) + '0');
	count++;

	return (count);
}
