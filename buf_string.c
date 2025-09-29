#include "main.h"

/**
 * buf_string - handles the %s specifier (buffered)
 * @s: string to print
 * @buffer: local buffer to store output
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters written
 */
int buf_string(char *s, char *buffer, int *buf_index)
{
	int count = 0, i;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		buffer[*buf_index] = s[i];
		(*buf_index)++;
		if (*buf_index == 1024)
		{
			write(1, buffer, *buf_index);
			*buf_index = 0;
		}
		count++;
	}
	return (count);
}
