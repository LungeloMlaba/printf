<<<<<<< HEAD
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format of printf
 * Return: Printed chars
 */
int _printf(const char *format, ...)
{
	int b, print = 0, print_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (b = 0; format && format[i] != '\0'; b++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[b];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &b);
			width = get_width(format, &b, list);
			precision = get_precision(format, &b, list);
			size = get_size(format, &b);
			++b;
			print = handle_print(format, &b, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_chars += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (print_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int i, stlen;
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
			for (stlen = 0; s[stlen] != '\0'; stlen++)
			{
				_putchar(s[stlen]);
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
