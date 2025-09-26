#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: is a character string. The
 *		format string is composed of zero or more directives.
 *
 * Return: the number of characters printed excluding the null byte.
 */

int _printf(const char *format, ...)
{
	va_list args;
	char *s, c;
	int i, j, count = 0; /* to track printed characters */

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++; /* move to specifier */
			if (format[i] == 'c')
			{
				c = va_arg(args, int); /* chars are promoted to int */
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				for (j = 0; s[j] != '\0'; j++)
				{
					write(1, &s[j], 1);
					count++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
