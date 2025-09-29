#include "main.h"

/**
 * buf_add - adds a single character to the buffer
 * @buffer: the output buffer
 * @buf_index: pointer to the current index in the buffer
 * @c: character to add
 *
 * Return: 1 (number of characters written)
 */
int buf_add(char *buffer, int *buf_index, char c)
{
	buf_addchar(buffer, buf_index, c);
	return (1);
}
