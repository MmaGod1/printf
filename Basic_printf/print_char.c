#include "main.h"

/**
 * print_char - prints a single character to standard output
 * @args: argument list containing the character to print
 *
 * Description: This function retrieves a character argument from
 * the va_list and writes it to standard output.
 *
 * Return: the number of characters printed (always 1).
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
