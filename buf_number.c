#include "main.h"

/**
 * buf_number - handles %d and %i specifiers (buffered)
 * @n: number to print
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_number(int n, char *buffer, int *buf_index)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		buf_addchar(buffer, buf_index, '-');
		count++;
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += buf_number(num / 10, buffer, buf_index);

	buf_addchar(buffer, buf_index, (num % 10) + '0');
	count++;

	return (count);
}
