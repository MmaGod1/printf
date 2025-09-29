#include "main.h"

/**
 * print_unknown - handles unsupported format specifiers
 * @spec: the unknown specifier character
 *
 * Description: This function writes a percent sign followed by the
 * unsupported specifier character, preserving the behavior of the
 * standard printf when encountering unrecognized specifiers.
 *
 * Return: the number of characters printed (always 2).
 */
int print_unknown(char spec)
{
	write(1, "%", 1);
	write(1, &spec, 1);
	return (2);
}
