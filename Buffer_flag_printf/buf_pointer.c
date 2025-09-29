#include "main.h"

/**
 * buf_pointer - handles %p specifier (buffered)
 * @ptr: pointer to print
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Return: number of characters added
 */
int buf_pointer(void *ptr, char *buffer, int *buf_index)
{
	unsigned long addr;
	char hex_digits[] = "0123456789abcdef";
	char tmp[20];  /* enough to hold 64-bit hex */
	int i = 0, count = 0;

	if (ptr == NULL)
	{
		char *nil = "(nil)";
		while (*nil)
		{
			buf_addchar(buffer, buf_index, *nil++);
			count++;
		}
		return (count);
	}

	addr = (unsigned long)ptr;

	/* prefix 0x */
	buf_addchar(buffer, buf_index, '0');
	buf_addchar(buffer, buf_index, 'x');
	count += 2;

	/* convert to hex (reverse order first) */
	do {
		tmp[i++] = hex_digits[addr % 16];
		addr /= 16;
	} while (addr != 0);

	/* add digits in correct order */
	while (i--)
	{
		buf_addchar(buffer, buf_index, tmp[i]);
		count++;
	}

	return (count);
}
