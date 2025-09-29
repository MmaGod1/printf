#include "main.h"

/**
 * buf_S - prints a string with non-printable chars as \xXX (buffered)
 * @s: input string
 * @buffer: local buffer
 * @buf_index: pointer to current buffer index
 *
 * Description:
 * For each character in the string:
 *   - If printable (ASCII 32 to 126), add it as-is to buffer.
 *   - Else, add "\x" followed by uppercase hex (2 digits).
 *
 * Return: number of characters added
 */
int buf_S(char *s, char *buffer, int *buf_index)
{
	int count = 0, i;
	char hex[2];

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		unsigned char c = s[i];

		if (c < 32 || c >= 127) /* non-printable */
		{
			buf_addchar(buffer, buf_index, '\\');
			buf_addchar(buffer, buf_index, 'x');
			count += 2;

			/* always two hex digits */
			hex[0] = "0123456789ABCDEF"[c / 16];
			hex[1] = "0123456789ABCDEF"[c % 16];

			buf_addchar(buffer, buf_index, hex[0]);
			buf_addchar(buffer, buf_index, hex[1]);
			count += 2;
		}
		else
		{
			buf_addchar(buffer, buf_index, c);
			count++;
		}
	}

	return (count);
}
