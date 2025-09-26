#include "main.h"

/**
 * print_hex - prints an unsigned int in hexadecimal (lowercase)
 * @n: the unsigned int to convert
 *
 * Description: This function converts an unsigned integer into
 * lowercase hexadecimal representation and writes it to stdout.
 *
 * Return: the number of characters printed.
 */
int print_hex(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 16)
		count += print_hex(n / 16);

	digit = (n % 16 < 10) ? (n % 16) + '0' : (n % 16) - 10 + 'a';
	write(1, &digit, 1);
	count++;

	return (count);
}
