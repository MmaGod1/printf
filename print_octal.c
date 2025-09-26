#include "main.h"

/**
 * print_octal - prints an unsigned int in octal
 * @n: the unsigned int to convert
 *
 * Description: This function converts an unsigned integer into
 * octal representation and writes it to stdout.
 *
 * Return: the number of characters printed.
 */
int print_octal(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 8)
		count += print_octal(n / 8);

	digit = (n % 8) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}
