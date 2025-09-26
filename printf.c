#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string composed of zero or more directives
 *
 * Description: This function emulates the standard printf function.
 * It handles the format specifiers %c, %s, %%, and also prints
 * unsupported specifiers as "%<char>".
 *
 * Return: the number of characters printed excluding the null byte,
 * or -1 if there is an error (e.g., dangling '%' at end of format).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0') /* Handle dangling '%' */
			{
				va_end(args);
				return (-1);
			}
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(va_arg(args, char *));
			else if (format[i] == '%')
				count += print_percent();
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));
			else if (format[i] == 'b')
				count += print_binary(va_arg(args, unsigned int));
			else
				count += print_unknown(format[i]);
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
