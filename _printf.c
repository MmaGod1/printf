#include "main.h"

#include "main.h"

/**
 * _printf - produces output according to a format using a local buffer
 * @format: a character string composed of zero or more directives
 *
 * Description: Same as printf, but accumulates output in a 1024-char buffer
 * and flushes only when full (or at the end). This reduces system calls.
 *
 * Return: number of characters printed (excluding null byte),
 * or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int buf_index = 0, count = 0, i;
	format_flags flags; /* declared once for C90 */

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

			/* reset flags */
			flags.plus = flags.space = flags.hash = 0;
			flags.width = 0;
			flags.minus = 0;
			flags.zero = 0;
			flags.length = 0;

			/* --- parse flags: +, space, #, -, 0 --- */
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#' ||
					format[i] == '-' || format[i] == '0')
			{
				if (format[i] == '+')
					flags.plus = 1;
				else if (format[i] == ' ')
					flags.space = 1;
				else if (format[i] == '#')
					flags.hash = 1;
				else if (format[i] == '-')
					flags.minus = 1;
				else if (format[i] == '0')
					flags.zero = 1;
				i++;
			}

			/* --- parse width (number or *) --- */
			if (format[i] == '*')
			{
				flags.width = va_arg(args, int);
				if (flags.width < 0)
				{
					flags.minus = 1;
					flags.width = -flags.width;
				}
				i++;
			}
			else
			{
				while (format[i] >= '0' && format[i] <= '9')
				{
					flags.width = flags.width * 10 + (format[i] - '0');
					i++;
				}
			}

			/* --- parse length modifiers: h, l --- */
			if (format[i] == 'h')
			{
				flags.length = 1;
				i++;
			}
			else if (format[i] == 'l')
			{
				flags.length = 2;
				i++;
			}

			/* check dangling '%' after parsing */
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			/* --- specifiers --- */
			if (format[i] == 'c')
				count += buf_char(args, buffer, &buf_index);

			else if (format[i] == 's')
				count += buf_string(va_arg(args, char *), buffer, &buf_index);

			else if (format[i] == '%')
				count += buf_percent(buffer, &buf_index);

			else if (format[i] == 'd' || format[i] == 'i')
			{
				if (flags.length == 2) /* long */
					count += buf_number_flags(va_arg(args, long), buffer, &buf_index, flags);
				else if (flags.length == 1) /* short */
					count += buf_number_flags((short)va_arg(args, int), buffer, &buf_index, flags);
				else
					count += buf_number_flags(va_arg(args, int), buffer, &buf_index, flags);
			}

			else if (format[i] == 'u')
			{
				if (flags.length == 2)
					count += buf_uint_flags(va_arg(args, unsigned long), buffer, &buf_index, flags);
				else if (flags.length == 1)
					count += buf_uint_flags((unsigned short)va_arg(args, unsigned int), buffer, &buf_index, flags);
				else
					count += buf_uint_flags(va_arg(args, unsigned int), buffer, &buf_index, flags);
			}

			else if (format[i] == 'o')
			{
				if (flags.length == 2)
					count += buf_octal_flags(va_arg(args, unsigned long), buffer, &buf_index, flags);
				else if (flags.length == 1)
					count += buf_octal_flags((unsigned short)va_arg(args, unsigned int), buffer, &buf_index, flags);
				else
					count += buf_octal_flags(va_arg(args, unsigned int), buffer, &buf_index, flags);
			}

			else if (format[i] == 'x')
			{
				if (flags.length == 2)
					count += buf_hex_flags(va_arg(args, unsigned long), buffer, &buf_index, flags, 0);
				else if (flags.length == 1)
					count += buf_hex_flags((unsigned short)va_arg(args, unsigned int), buffer, &buf_index, flags, 0);
				else
					count += buf_hex_flags(va_arg(args, unsigned int), buffer, &buf_index, flags, 0);
			}

			else if (format[i] == 'X')
			{
				if (flags.length == 2)
					count += buf_hex_flags(va_arg(args, unsigned long), buffer, &buf_index, flags, 1);
				else if (flags.length == 1)
					count += buf_hex_flags((unsigned short)va_arg(args, unsigned int), buffer, &buf_index, flags, 1);
				else
					count += buf_hex_flags(va_arg(args, unsigned int), buffer, &buf_index, flags, 1);
			}

			else if (format[i] == 'S')
				count += buf_S(va_arg(args, char *), buffer, &buf_index);

			else if (format[i] == 'p')
				count += buf_pointer(va_arg(args, void *), buffer, &buf_index);

			else
				count += buf_unknown(format[i], buffer, &buf_index);
		}
		else
		{
			buf_addchar(buffer, &buf_index, format[i]);
			count++;
		}
	}

	if (buf_index > 0)
		write(1, buffer, buf_index);

	va_end(args);
	return (count);
}
