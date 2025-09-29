#include "main.h"

/**
 * _printf_buf - produces output according to a format using a local buffer
 * @format: a character string composed of zero or more directives
 *
 * Description: Same as _printf, but accumulates output in a 1024-char buffer
 * and flushes only when full (or at the end). This reduces system calls.
 *
 * Return: the number of characters printed excluding the null byte,
 * or -1 if there is an error (e.g., dangling '%' at end of format).
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int buf_index = 0, count = 0, i;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			if (format[i] == 'c')
				count += buf_char(args, buffer, &buf_index);
			else if (format[i] == 's')
				count += buf_string(va_arg(args, char *), buffer, &buf_index);
			else if (format[i] == '%')
				count += buf_percent(buffer, &buf_index);
			else if (format[i] == 'd' || format[i] == 'i')
				count += buf_number(va_arg(args, int), buffer, &buf_index);
			else if (format[i] == 'b')
				count += buf_binary(va_arg(args, unsigned int), buffer, &buf_index);
			else if (format[i] == 'u')
				count += buf_uint(va_arg(args, unsigned int), buffer, &buf_index);
			else if (format[i] == 'o')
				count += buf_octal(va_arg(args, unsigned int), buffer, &buf_index);
			else if (format[i] == 'x')
				count += buf_hex(va_arg(args, unsigned int), buffer, &buf_index);
			else if (format[i] == 'X')
				count += buf_HEX(va_arg(args, unsigned int), buffer, &buf_index);
			else
				count += buf_unknown(format[i], buffer, &buf_index);
		}
		else
		{
			buffer[buf_index++] = format[i];
			if (buf_index == 1024)
			{
				write(1, buffer, buf_index);
				buf_index = 0;
			}
			count++;
		}
	}

	if (buf_index > 0) /* flush remaining data */
		write(1, buffer, buf_index);

	va_end(args);
	return (count);
}
