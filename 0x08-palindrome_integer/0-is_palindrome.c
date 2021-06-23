#include <stdio.h>
#include <stdlib.h>
/**
 * is_palindrome- finds if a number is palindrome
 * @n: unsigned long number
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long number = 0;
	unsigned long aux = 0;
	unsigned long number_reversed = 0;

	number = n;
	while (n != 0)
	{
		aux = n % 10;
		number_reversed = number_reversed * 10 + aux;
		n = n / 10;
	}

	if (number == number_reversed)
		return (1);

	return (0);
}
