#include "main.h"

/**
 * print_unsigned - prints an unsigned integer in decimal
 * @n: the unsigned integer to print
 *
 * Description: This function converts an unsigned integer into
 * its decimal string representation and writes it to stdout.
 *
 * Return: the number of characters printed.
 */
int print_unsigned(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 10)
		count += print_unsigned(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}
