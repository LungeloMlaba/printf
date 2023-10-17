#include "main.h"

/**
 * printf_pointer - prints an hexadecimal number.
 * @val: num of arguments
 * Return: num of chars printed
 */

int printf_pointer(va_list val)
{
	void *p;
	char *s = "(nil)";
	long int a;
	int k;
	int i;

	p = va_arg(val, void*);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	k = printf_hexad_alt(a);
	return (k + 2);
}
