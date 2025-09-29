#include "main.h"

/**
 * print_binary - prints the binary representation of an unsigned int
 * @n: number to be converted to binary
 *
 * Description: This function converts an unsigned integer into
 * its binary representation and writes it to standard output.
 *
 * Return: the number of characters printed.
 */
int print_binary(unsigned int n)
{
	int count = 0;
	char bit;

	if (n / 2)
		count += print_binary(n / 2);

	bit = (n % 2) + '0';
	write(1, &bit, 1);
	count++;

	return (count);
}
