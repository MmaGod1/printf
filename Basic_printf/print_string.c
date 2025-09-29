#include "main.h"

/**
 * print_string - prints a string to standard output
 * @s: pointer to the string to be printed
 *
 * Description: This function writes the characters of a string
 * one by one to standard output using the write system call.
 * If @s is NULL, the string "(null)" is printed instead.
 *
 * Return: the number of characters printed.
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
