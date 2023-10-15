#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int i, slen;
	va_list args;
	char c;
	char *s;
	int n;
	/*char *checker = "cs";*/
	/*{
		{"%s", printf_string}, {"%c", printf_char},
	}*/
	
	va_start(args, format);
	n = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(args, int);
			_putchar(c);
			n++;
			i+=2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(args, char*);
			for (slen = 0; s[slen] != '\0'; slen++)
			{
				_putchar(s[slen]);
			}
			i+=2;
			n++;
		}
		else
		{
			_putchar(format[i]);
			n++;
		}
	}
	return (n);
}
