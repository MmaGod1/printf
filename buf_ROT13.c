#include "main.h"
#include <string.h>

/**
 * buf_rot13 - handles the %R specifier (ROT13 encoding)
 * @str: string to print
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_rot13(char *str, char *buffer, int *buf_index)
{
	int i, count = 0;
	char c;

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		c = str[i];

		if ((c >= 'A' && c <= 'Z'))
			c = ((c - 'A' + 13) % 26) + 'A';
		else if ((c >= 'a' && c <= 'z'))
			c = ((c - 'a' + 13) % 26) + 'a';

		count += buf_add(buffer, buf_index, c);
	}

	return (count);
}
