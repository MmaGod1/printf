#include "main.h"

/**
 * print_string - prints a string to standard output
 * @s: pointer to the string to be printed
 *
 * Description: This function writes the characters of a string
 * one by one to the standard output using the write system call.
 * If @s is NULL, the string "(null)" is printed instead.
 *
 * Return: the number of characters printed
 */
int print_string(char *s)
{
	int count = 0, j;

	if (s == NULL)
		s = "(null)";
	for (j = 0; s[j] != '\0'; j++)
	{
		write(1, &s[j], 1);
		count++;
	}
	return (count);
}

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
	char c;
	int i, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
				count += print_string(va_arg(args, char *));
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i] == '!')
			{
				write(1, "%!", 2);
				count += 2;
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
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
