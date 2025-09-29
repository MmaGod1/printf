#include "main.h"

/**
 * buf_binary - handles %b specifier (buffered)
 * @n: unsigned int to print in binary
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_binary(unsigned int n, char *buffer, int *buf_index)
{
	int count = 0;

	if (n / 2)
		count += buf_binary(n / 2, buffer, buf_index);

	buf_addchar(buffer, buf_index, (n % 2) + '0');
	count++;

	return (count);
}
