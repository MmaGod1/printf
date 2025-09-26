#include "main.h"

/**
 * print_percent - prints a percent sign
 *
 * Description: This function writes a literal percent sign to
 * standard output when the format specifier is '%%'.
 *
 * Return: the number of characters printed (always 1).
 */
int print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
