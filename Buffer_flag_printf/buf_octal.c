#include "main.h"

/**
 * buf_octal - handles %o specifier (buffered)
 * @n: unsigned int to print in octal
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_octal(unsigned int n, char *buffer, int *buf_index)
{
	int count = 0;

	if (n / 8)
		count += buf_octal(n / 8, buffer, buf_index);

	buf_addchar(buffer, buf_index, (n % 8) + '0');
	count++;

	return (count);
}
