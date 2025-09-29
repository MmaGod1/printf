#include "main.h"

/**
 * buf_hash_flag - handles '#' flag for o, x, X
 * @specifier: format specifier ('o', 'x', 'X')
 * @n: unsigned int to print
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_hash_flag(char specifier, unsigned int n,
		char *buffer, int *buf_index)
{
	int count = 0;

	if (n == 0)
		return buf_number(n, buffer, buf_index); /* no prefix */

	if (specifier == 'o')
	{
		buf_addchar(buffer, buf_index, '0');
		count++;
		count += buf_octal(n, buffer, buf_index);
	}
	else if (specifier == 'x')
	{
		buf_addchar(buffer, buf_index, '0');
		buf_addchar(buffer, buf_index, 'x');
		count += 2;
		count += buf_hex(n, buffer, buf_index);
	}
	else if (specifier == 'X')
	{
		buf_addchar(buffer, buf_index, '0');
		buf_addchar(buffer, buf_index, 'X');
		count += 2;
		count += buf_HEX(n, buffer, buf_index);
	}

	return (count);
}
