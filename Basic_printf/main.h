#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Main printf function */
int _printf(const char *format, ...);

/* Helper print functions */
int print_char(va_list args);
int print_string(char *s);
int print_percent(void);
int print_unknown(char spec);
int print_number(int n);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n);
int print_HEX(unsigned int n);


#endif
