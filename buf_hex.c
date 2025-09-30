#include "main.h"

/**
 * buf_HEX - handles %X specifier (buffered, uppercase)
 * @n: unsigned int to print in hex
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_HEX(unsigned int n, char *buffer, int *buf_index)
{
	char *digits = "0123456789ABCDEF";
	int count = 0;

	if (n / 16)
		count += buf_HEX(n / 16, buffer, buf_index);

	buf_addchar(buffer, buf_index, digits[n % 16]);
	count++;

	return (count);
}
