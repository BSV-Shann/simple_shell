#include "main.h"

/**
 * print_number - Prints an unsigned number.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of digits printed.
 */
int print_number(int n)
{
	int divisor = 1;
	int length = 0;
	unsigned int number = (unsigned int)n;

	while (number / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		length += _write_char('0' + number / divisor);
		number %= divisor;
		divisor /= 10;
	}

	return (length);
}

