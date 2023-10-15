#include "main.h"

/**
 * printf_unsigned_int - prints unsigned integer
 * @args: arguments to print
 * Return: number of characters printed
 */

int printf_unsigned_int(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, end = n % 10, dig, pow = 1, i = 1;

	n = n / 10;
	num = n;

	if (end < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		end = -end;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			pow = pow * 10;
			num = num / 10;
		}
		num = n;
		while (pow > 0)
		{
			dig = num / pow;
			_putchar(dig + '0');
			num = num - (dig * pow);
			pow = pow / 10;
			i++;
		}
	}
	_putchar(end + '0');

	return (i);
}
