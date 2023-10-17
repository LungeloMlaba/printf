#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} checker;

int printf_char37(void);
int printf_rot13(va_list args);
int printf_reversed_string(va_list args);
int printf_HEXAD_alt(unsigned int n);
int printf_hexad_alt(unsigned long int n);
int printf_pointer(va_list val);
int printf_extra_string(va_list val);
int printf_HEXAD(va_list val);
int printf_hexad(va_list val);
int printf_octal(va_list val);
int printf_unsigned_int(va_list args);
int printf_binary(va_list val);
int printf_int(va_list args);
int printf_dec(va_list args);
int _strlen(char *s);
int printf_char(va_list val);
int printf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
