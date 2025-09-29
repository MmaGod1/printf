#include "main.h"

/**
 * _printf - produces output according to a format using a local buffer
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
	int buf_index = 0;
	int count = 0;
	int i = 0;
	format_flags flags; /* keep at top for C90 */

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			/* move to char after '%' */
			i++;
			/* simple dangling "%" (nothing after '%') */
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			/* reset flags */
			flags.plus = flags.space = flags.hash = 0;

			/* parse flags: +, space, # */
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				if (format[i] == '+')
					flags.plus = 1;
				else if (format[i] == ' ')
					flags.space = 1;
				else if (format[i] == '#')
					flags.hash = 1;
				i++;
			}

			/* --- IMPORTANT: check for dangling '%' AFTER parsing flags --- */
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			/* now format[i] is the specifier */
			if (format[i] == 'c')
				count += buf_char(args, buffer, &buf_index);
			else if (format[i] == 's')
				count += buf_string(va_arg(args, char *), buffer, &buf_index);
			else if (format[i] == '%')
				count += buf_percent(buffer, &buf_index);
			else if (format[i] == 'd' || format[i] == 'i')
				count += buf_number_flags(va_arg(args, int), buffer, &buf_index, flags);
			else if (format[i] == 'b')
				count += buf_binary(va_arg(args, unsigned int), buffer, &buf_index);
			else if (format[i] == 'u')
				count += buf_uint_flags(va_arg(args, unsigned int), buffer, &buf_index, flags);
			else if (format[i] == 'o')
				count += buf_octal_flags(va_arg(args, unsigned int), buffer, &buf_index, flags);
			else if (format[i] == 'x')
				count += buf_hex_flags(va_arg(args, unsigned int), buffer, &buf_index, flags, 0);
			else if (format[i] == 'X')
				count += buf_hex_flags(va_arg(args, unsigned int), buffer, &buf_index, flags, 1);
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

	if (buf_index > 0) /* flush remaining data */
		write(1, buffer, buf_index);

	va_end(args);
	return (count);
}
