#include "main.h"

/**
 * buf_reverse - handles the %r specifier (reversed string)
 * @str: string to print
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_reverse(char *str, char *buffer, int *buf_index)
{
	int len, i, count = 0;

	if (!str)
		str = "(null)";

	len = strlen(str);

	for (i = len - 1; i >= 0; i--)
		count += buf_add(buffer, buf_index, str[i]);

	return (count);
}
