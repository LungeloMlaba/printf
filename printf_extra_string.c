#include "main.h"

/**
 * printf_extra_string - print exclusuives string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int printf_extra_string(va_list val)
{
	char *s;
	int i; 
	int l = 0;
	int t;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			l = l + 2;
			t = s[i];
			if (t < 16)
			{
				_putchar('0');
				l++;
			}
			l = l + printf_HEXAD_alt(t);
		}
		else
		{
			_putchar(s[i]);
			l++;
		}
	}
	return (l);
}
