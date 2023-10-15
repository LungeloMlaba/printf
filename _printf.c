#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	checker r[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%i", printf_int}, {"%d", printf_dec},
		{"%b", printf_binary}
	};

	va_list args;
	int i = 0, j, chars_printed = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		int match_found = 0;

		j = 0;
		while (j < 5)
		{
			if (r[j].id[0] == format[i] && r[j].id[1] == format[i + 1])
			{
				chars_printed += r[j].f(args);
				i = i + 2;
				match_found = 1;
				break;
			}
			j++;
		}
		if (!match_found)
		{
			_putchar(format[i]);
			chars_printed++;
			i++;
		}
	}
	va_end(args);
	return (chars_printed);
}
